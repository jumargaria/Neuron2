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
#include "neuron.hpp"
class Network {
    public:
//====================Constructor/Destructor==================
    Network (unsigned int nbr_neurons, long neurones_excit, long neurones_inhib) ;
    ~Network(){};
//====================Setters//Getters==================
    /**
     * Getter for Neurons_
     @return all the neurons in the network
     */
    std::vector<Neuron> getNeurons()const;
    /**
     * Getter Connections
     @return all the connections between the neurones
     */
    std::vector<std::vector<int> > getConnections () const;
    /**
     * Getter NE_
     @return number of excitatory neurons in the network
     */
    long getNE()const;
    /**
     * Getter NI_
     @return number of inhibitory neurons in the network
     */
    long getNI()const;
    /**
     * Getter CE_
     @return number of connection with excitatory neurons for each neuron
     */
    long getCE()const;
    /**
     * Getter CI_
     @return number of connection with inhibitory neurons for each neuron
     */
    long getCI()const;
    /**
     * Getter NbrNeuron_
     @return number of neuron in the network
     */
    long getNbrNeurons()const;
    
//====================Update==================
    /**
     update the state of the network until the time 't_stop'
     @param tstop: the time ...????
     */
    void update( unsigned long tstop);
    
    private:
//====================Attributs==================

    std::vector<Neuron> Neurons_;//!< vector of all neurons
    std::vector<std::vector<int> >Connections_;//!< connections between the different neurons
    unsigned long NE_;//!<Number of neurons excitatory
    unsigned long NI_;//!< Number of inhibitory neurons
    unsigned long NbrNeuron_;//!< total number of neurons
    unsigned long  CE_;//!<connections from the excitatory neurons in the network
    unsigned long  CI_;//!<connections from the inhibitory neurons in the network
    unsigned long  C_EXT;//!< number of connections from outside the network
    


};
#endif /* Network_hpp */
