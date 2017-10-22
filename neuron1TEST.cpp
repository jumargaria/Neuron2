#include "neuron1.hpp"
#include <iostream>
#include <cmath>
#include "gtest/gtest.h"

TEST(neuron1TEST, MembranePotential_){
            Neuron n;
            n.setI_ext(1.0);
            
            //First update test
            n.update(1,1000);
            EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0))- n.getMembranePotential(),0.0);
            
        }

TEST(neuron1TEST, MembranePotential_){
    Neuron n;
    int nbr_spikes(0);
     n.setI_ext(1.01);
    //Second update test
     n.update(1,1000);
    if (spike){
    EXPECT_EQ(n.getMembranePotential()-20.0, 0.0)
    }


}

int main(int argc, char **argv){
            ::testing::InitGoogleTest(&argc,argv);
            return RUN_ALL_TESTS();
            
        }
