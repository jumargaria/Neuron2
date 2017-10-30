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
    bool update(long steps);
//====================Getters//Setters==================
    void setI_ext(double I);
    double getIext()const;
    long getTimeSpike()const;
    double getMembranePotential()const;
    void setMembranePotential(double MP);
    void setBuffer(int valeur);
    long getRefractoryStep()const;
    long getNbrSpikes()const ;
    double getJ()const;
    void setJ( double j);
    
    
//====================Convertor==================  
    std::string double_to_string(double c)const;
//====================Fonctions==================
    void receive(unsigned long arrival, double j);
     
    
    
    private:
    
//====================Attributs==================
    double MembranePotential_;//Membrane Potential
    long NbSpikes_; //Number of spike
    long TimeSpikes_;//Time of the last spike
    bool refractory_;//return true if the state is refractory
    double RefractoryStep_;//Refractory time in steps
    long tsim_;//clock
    double Iext_;//external current
    std::vector<int> Buffer_;
    double c1;//constant of integration
    double c2;//constant of integration
    double J;// weight of the connections that provides the current neurone

};

#endif /* neuron_hpp */
