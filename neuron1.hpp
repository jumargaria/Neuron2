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
    long getTimeSpike()const;
    double getMembranePotential()const;
    void setMembranePotential(double MP);
    void setNeurons_post(std::vector<Neuron*>);
    std::vector<Neuron*> getNeurons_post();
    long gettsim()const;
    
//====================Convertor==================  
    std::string double_to_string(double c)const;
//====================Fonctions==================
    void receive(long Tpre,double J);
     
    
    
    private:
    
//====================Attributs==================
    double MembranePotential_;
    long NbSpikes_;
    long TimeSpikes_;
    bool refractory_;
    double RefractoryStep_;
    long tsim_;
    double Iext_;
    std::vector<Neuron*>Neurons_post;
    
    

};

#endif /* neuron_hpp */
