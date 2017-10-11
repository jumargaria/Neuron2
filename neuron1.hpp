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
    bool update(long steps, long clock);
//====================Getters//Setters==================
    void setI_ext(double I);
    long getTimeSpike()const;
    double getMembranePotential()const;
    void setMembranePotential(double MP);
    void setNeuron_post( Neuron* n);
    std::vector<Neuron*> getNeurons_post();
    void setBuffer(int valeur);
    
    
//====================Convertor==================  
    std::string double_to_string(double c)const;
//====================Fonctions==================
    void receive(double nbr_spike);
     
    
    
    private:
    
//====================Attributs==================
    double MembranePotential_;
    long NbSpikes_; //Number of spike
    long TimeSpikes_;//Time of the last spike
    bool refractory_;//retunr true if the state is refractory
    double RefractoryStep_;
    long tsim_;//clock
    double Iext_;//external current
    std::vector<Neuron*>Neurons_post;
    std::vector<int> Buffer_;
    

};

#endif /* neuron_hpp */
