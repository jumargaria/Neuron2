//
//  neuron.hpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#ifndef neuron_hpp
#define neuron_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>

class Neuron{
    
    public:
//====================Constructors---Destructors==================
    Neuron();
    ~Neuron(){};
//====================Update================== 
    bool update(long steps, long clock);//reponsible of all the update of membrane potential at each time
//====================Getters//Setters==================
    void setI_ext(double I); // Iext= I
    double getIext()const;//return the current Iext
    long getTimeSpike()const;//return the last time spiking
    double getMembranePotential()const;//return the current membrane potential
    void setMembranePotential(double MP);// Membrane potential = MP
    void setBuffer(int indice);//add +1 to the "indice" part of the buffer
    
    
//====================Convertor==================  
    std::string double_to_string(double c)const;// convert a string into a double ( useful to write the membrane potential value in the .txt file
    
//====================Functions==================
    void receive(double nbr_spike); // function responsible of adding J times the number present in the buffer ( corresponding to the number of pre synaptic neurone that spike at a time t)
     
    
    
    private:
    
//====================Attributs==================
    double MembranePotential_;// Membrane Potential 
    long NbSpikes_; //Number of spike
    long TimeSpikes_;//Time of the last spike
    bool refractory_;//return true if the state is refractory
    double RefractoryStep_;// Refractory time in step
    long tsim_;//clock
    double Iext_;//external current
    std::vector<int> Buffer_;// to store the spike and deliver it in right time t+ D
    double c1; // constant of integration
    double c2;// constant of integration
    

};

#endif /* neuron_hpp */
