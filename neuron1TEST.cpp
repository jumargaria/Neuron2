#include "neuron1.hpp"
#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "constants.hpp"

TEST(neuron1TEST, MembranePotential_){
    Neuron neuron;
    neuron.setI_ext(1.0);
    
    //First update test
    neuron.update(1,1000);
    EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0))- neuron.getMembranePotential(),0.0);
    // Test after several updates
    /// 1 :
    neuron.update(10000,1000);
   //MembranePotential_ should tend towards 20 but never spike
    EXPECT_EQ(0,neuron.getNbrSpikes());
    EXPECT_GT(1E-3,std::fabs(19.999- neuron.getMembranePotential()));
    // 2 :
    neuron.setI_ext(0.0);
    neuron.update(2000,1000);
    EXPECT_NEAR(0, neuron.getMembranePotential(), 1E-3);
}
TEST(NeuronTEST, NegativeInput){
    Neuron n;
    n.setI_ext(-1.0);
    
    //First update test
    n.update(1, 1000);
    EXPECT_EQ(-20.0*(1.0-exp(-0.1/20.0))- n.getMembranePotential(),0);
    
    //Test after several updates
    //*1*
    n.update(10000,1000);
    //MembranePotential_ should tend towards 20 but never spike
    EXPECT_EQ(0,n.getNbrSpikes());
    EXPECT_GT(1E-3, std::fabs(-19.9999 - n.getMembranePotential()));
    //*2*
    //MembranePotential_ decay towards 0 without input current
    n.setI_ext(0.0);
    n.update(2000,1000);
    EXPECT_NEAR(0,n.getMembranePotential(), 1E-3);
}
//=====================SpikeTime========================

TEST(neuron1TEST, TimeSpikes_){
    Neuron neurone;
    neurone.setI_ext(1.01);
    
    neurone.update(924 , 1000);
    EXPECT_EQ(0, neurone.getNbrSpikes());
    neurone.update(1, 1000);
    EXPECT_EQ(1,neurone.getNbrSpikes());
    EXPECT_EQ(0.0, neurone.getMembranePotential());
    
    neurone.update(944,1000);
    EXPECT_EQ(1, neurone.getNbrSpikes());
    neurone.update(1,1000+ 945);
    EXPECT_EQ(2, neurone.getNbrSpikes());
}

//=====================Post-Synaptic========================

TEST(TwoNeurons, NoPostSYnapticSpike){
    Neuron neuron1;
    Neuron neurone2;
    
    neuron1.setI_ext(1.01);
    for (int i=0; i<925+13;++i){
        if (neuron1.update(1,1000+i)){
            EXPECT_EQ(0.0, neuron1.getMembranePotential());
            neurone2.setBuffer(1);
        }
        neurone2.update(1,1000+i);
    }
    
    EXPECT_EQ(0.1, neurone2.getMembranePotential());
    
}
TEST(TwoNeurons, WITHPostSynapticSpike){
    Neuron neurone1;
    Neuron neurone2;
    
    neurone1.setI_ext(1.01);
    neurone2.setI_ext(1.0);
    
    for (int i=0; i<1869+13;++i){
        if (neurone1.update(1,1000+i)){
            EXPECT_EQ(0.0, neurone1.getMembranePotential());
            neurone2.setBuffer(1);
        }
        neurone2.update(1,1000+i);
    }
    EXPECT_EQ(0, neurone2.getNbrSpikes());
    neurone2.update(1,1869+1000+13);
    EXPECT_EQ(0, neurone2.getMembranePotential());
    EXPECT_EQ(1,neurone2.getNbrSpikes());
    
}


int main(int argc, char **argv){
            ::testing::InitGoogleTest(&argc,argv);
            return RUN_ALL_TESTS();
            
        }
