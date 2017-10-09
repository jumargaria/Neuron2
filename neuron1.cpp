//
//  neuron.cpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#include "neuron1.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include "constants.hpp"
#include <cassert>
#include <vector>
 

//====================Constructor==================
Neuron:: Neuron():MembranePotential_(0.0),NbSpikes_(0.0),TimeSpikes_(0.0),refractory_(false), RefractoryStep_(0.0),tsim_(0.0),Iext_(0.0) {}

//====================Setters//Getters==================
void Neuron:: setI_ext(double I){Iext_=I;}
long Neuron:: getTimeSpike()const { return TimeSpikes_; }
void Neuron:: setMembranePotential(double MP){ MembranePotential_=MP; }
double Neuron:: getMembranePotential()const { return MembranePotential_; }
long Neuron::gettsim()const { return tsim_; }
void Neuron::setNeurons_post(std::vector<Neuron*>N){Neurons_post=N;}
std::vector<Neuron*> Neuron:: getNeurons_post(){return Neurons_post;}
//====================Convertor==================
std::string Neuron::double_to_string(double c)const{
std::stringstream ss;
ss << c;
std::string str = ss.str();
    return str;
}

//====================Fonctions==================
void Neuron::receive(long Tpre,double J){//?????
    setMembranePotential(getMembranePotential()+J);
    
}

//====================Update==================
bool Neuron:: update(long steps){
    bool spike=false;

    if(steps<=0) return false;
    
    const long t_stop =tsim_+steps;
    
    while(tsim_<t_stop){
        
        if(refractory_){
            MembranePotential_= 0.0;
            ++RefractoryStep_;
            
             if(RefractoryStep_ > REF_STEPS) {
               RefractoryStep_=0;
               refractory_=false;
            }
            
        }else if(MembranePotential_>THRESHOLD){
            
            ++NbSpikes_;
            TimeSpikes_= tsim_;
            refractory_= true;
            spike=true;
        }
     MembranePotential_= exp(-h/TAU)* MembranePotential_+ Iext_*RESISTANCE*(1-exp(-h/TAU));
      ++tsim_;
    }
    return spike;
}





