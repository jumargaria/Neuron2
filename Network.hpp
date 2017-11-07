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
/**
 * @class Network
 * brief class to simulate a network 
 * 12500 neurons in all stored in a vector : Neurons
 * with 10000 excitatory neurons and 2500 inhibitory neurons
 * generate connections in a random way 
 * ( 1000 excitatory connections and 250 inhibitory connections for each neurons)
 * update each neurons in a periode of time 
 */
class Network {
    public:
//====================Constructor/Destructor==================
    /**
     * Constructor
     */
    Network ();
    /**
     * Destructor
     */
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
    std::vector<std::vector<unsigned int> > getConnections () const;
 
   
    
//====================Update==================
    /**
     * update the state of the network until the time 't_stop'
     @param tstop: the time of the last update for each neurons
     */
     
    void update( unsigned long t_stop);
    
    private:
//====================Attributs==================

    std::vector<Neuron> Neurons_;//!< vector of all neurons
    std::vector<std::vector<unsigned int> >Connections_;//!< vector of connections between the all neurons

};
#endif /* Network_hpp */
