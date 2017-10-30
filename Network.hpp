//
//  Network.hpp
//  
//
//  Created by Juliette Margaria on 30/10/2017.
//
//

#ifndef Network_hpp
#define Network_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include "neuron1.hpp"
class Network {
    public:
    Network (unsigned int nbr_neurons, long neurones_excit, long neurones_inhib) ;
    ~Network(){};
    void update( long tstop);
    
    private:
    std::vector<Neuron> Neurons_;
    std::vector<std::vector<int> >Connections_;
    long NE_;
    long NI_;
    long NbrNeuron_;
    



};
#endif /* Network_hpp */
