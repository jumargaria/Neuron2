//
//  neuron.hpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#ifndef neuron_hpp
#define neuron_hpp
#include "constants.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
/**
 * @class Neuron
 * brief class to simulate a neuron
 * Update the membrane potential for a certain number of steps, add the buffer which represents the connections weight of the other neurons with the delay 
 * The neuron spikes if its membrane potential rise the Threshold( 20 mV)
 * Set the neuron to refractory just after the spike and reset the membrane potential 0.0 For a period of time (timerefractory)
 * 
 */
class Neuron{
    public:
//====================Constructors---Destructors==================
    /**
     * Constructor
     @param background_noise : the poisson distribution , useful for the TESTS, 
     return true if we want the conections for the rest of the brain
     */
    Neuron(bool background_noise);
    /**
     * Destructor
     */
    ~Neuron(){};
//====================Getters//Setters==================
    
    /**
     * Getter for external current
     @return current value of External current
     */
    double getIext()const;
    /**
     * Getter for Time Spike
     @return current value of Spike time
     */
    
    long getTimeSpike()const;
    /**
     * Getter for Refractory Time in step
     @return current value of RefractoryStep
     */
    long getRefractoryStep()const;
    /**
     * Getter for Membrane potential
     @return current value of Membrane Potential
     */
    double getMembranePotential()const;
    /**
     * Getter for Number of spike
     @return current value of Number of spike
     */
    long getNbrSpikes()const ;
    /**
     * Getter for J
     @return current value of J
     */
    double getJ()const;
    /**
     Set Membrane Potential
     @param MP: Membrane potential
     */
    void setMembranePotential(double MP);
    /**
     Set external current
     @param i_ext: external current
     */
    void setI_ext(double i_ext);
    /**
     Set J
     @param j: weight of the connection in mV
     */
    void setJ( double j);
    
//====================Fonctions==================
    /**
     Receive a sike a time arrival with wheight j.
     If more than one spike arrives at the same time, j is the sum of all of them
     @param arrival: time (in step) at which the spike arrives
     @param j: weight of the connection in mV
     */
    void receive(unsigned long arrival, double j);
//====================Update==================
    /**
     update the state of the neurone each time t
     @param steps: number of simulation steps
     */
    bool update(long steps);
    
    
    private:
    
//====================Attributs==================
    double MembranePotential_;//!<Membrane Potential
    unsigned long NbSpikes_; //!<Number of spike
    unsigned long TimeSpikes_;//!<Time of the last spike
    bool refractory_;//!<return true if the state is refractory
    unsigned long RefractoryStep_;//!<Refractory time in steps
    unsigned long tsim_;//!<clock
    double Iext_;//!<external current
    std::vector<double> Buffer_;//!< buffer for spike
    double c1;//!<constant for integration
    double c2;//!<constant for integration
    double J;//!< weight of the connections that provides the current neuron
    bool background_noise_;//!< To add or not the poisson distributions (easier for the test)
};

#endif /* neuron_hpp */
