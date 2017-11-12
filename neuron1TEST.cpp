
#include "Network.hpp"
#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
/**
 * @class TESTS
 * brief class to test
 *
 */
// Test the right value of Membrane Potential
TEST(Single_neuron, MembranePotential_){
    Neuron neuron(false);
    neuron.setI_ext(1.0);
    
    //First update test
    neuron.update(1);
    EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0))- neuron.getMembranePotential(),0.0);
    // Test after numerous updates
    neuron.update(10000);
    EXPECT_EQ(0,neuron.getNbrSpikes());
    EXPECT_GT(1E-3,std::fabs(19.999- neuron.getMembranePotential()));
    
    neuron.setI_ext(0.0);
    neuron.update(20000);
    EXPECT_NEAR(0, neuron.getMembranePotential(), 1E-4);
}
// Test the right value of TimeSpikes_
TEST(Single_neuron, TimeSpikes_){
    Neuron neuron(false);
    neuron.setI_ext(1.01);
    neuron.update(924 );
    EXPECT_EQ(0, neuron.getNbrSpikes());
    neuron.update(1);
    EXPECT_EQ(1,neuron.getNbrSpikes());
    EXPECT_EQ(0.0, neuron.getMembranePotential());
    
    neuron.update(944);
    EXPECT_EQ(1, neuron.getNbrSpikes());
    neuron.update(1);
    EXPECT_EQ(2, neuron.getNbrSpikes());
}
// Test the right connection between two neurons withhout post synaptic spike
TEST(Two_neurons, NoPostSYnapticSpike){
    Neuron neuron1(false);
    Neuron neuron2(false);
    
    neuron1.setI_ext(1.01);
    for (unsigned int i(0); i<925+DELAY+1;++i){
        if (neuron1.update(1)){
			
            EXPECT_EQ(0.0, neuron1.getMembranePotential());
            neuron2.update(1);
            neuron2.receive(i,neuron1.getJ());
        }else{
        
        neuron2.update(1);
        }
        EXPECT_EQ(0, neuron2.getNbrSpikes());
    }
EXPECT_EQ(0.1, neuron2.getMembranePotential());
}

// Test th right connection between two neurons with post synaptic spike
TEST(Two_neurons, WITHPostSynapticSpike){
    Neuron neuron1(false);
    Neuron neuron2(false);
    
    neuron1.setI_ext(1.01);
    neuron2.setI_ext(1.0);
    
    for (unsigned int i(0); i<1870+DELAY+1;++i){
        if (neuron1.update(1)){
            EXPECT_EQ(0.0, neuron1.getMembranePotential());
            neuron2.update(1);
            neuron2.receive(i,neuron1.getJ());
        }else{
        neuron2.update(1);
    }
    }
    EXPECT_EQ(0, neuron2.getNbrSpikes());
    neuron2.update(1);
    EXPECT_EQ(0, neuron2.getMembranePotential());
    EXPECT_EQ(1,neuron2.getNbrSpikes());
    
}

// Test the right value of J for each neurons of the network
TEST(Networks,right_J){
    Network net;
    std::vector<Neuron> Neurons=net.getNeurons();
    unsigned long N(Neurons.size());
    for ( unsigned int i(0); i< N; ++i ){
		
        if(i<NE){
        EXPECT_EQ(JE, Neurons[i].getJ());
        }else{
        EXPECT_EQ(JI,Neurons[i].getJ());
        }
    }
}

TEST(Networks, Connections){
    Network net;   
    std::vector<std::vector<unsigned int> >Connect (NbrNeuron, std::vector<unsigned int>(2,0));  
     std::vector<std::vector<unsigned int> >connections = net.getConnections() ;
   unsigned long N (connections.size());
     for (unsigned int i(0); i<N; ++i){
        unsigned long Neuron_i_send_size(connections[i].size());
        
        for (unsigned int j(0); j<Neuron_i_send_size; ++j ){
            std::vector<unsigned int> neurons_i = connections[i];

                      if(i < NE){
           ++Connect[neurons_i[j]][0];
  
            }else{
                
                ++Connect[neurons_i[j]][1];
            }
        }
   }
     
    for (unsigned int i(0); i<NbrNeuron; ++i){
        EXPECT_EQ(CE,Connect[i][0] );
        EXPECT_EQ(CI, Connect[i][1]);
    }
    
} 

int main(int argc, char **argv){
            ::testing::InitGoogleTest(&argc,argv);
            return RUN_ALL_TESTS();
            
        }

