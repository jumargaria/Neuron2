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
#include <random>
//====================Constructor==================
Neuron:: Neuron():MembranePotential_(0.0),NbSpikes_(0.0),TimeSpikes_(0.0),refractory_(false), RefractoryStep_(0.0),tsim_(0.0),Iext_(0.0),J(JE){
    for(size_t i(0);i<(D+1);++i){
        Buffer_.push_back(0.0);
    }
        c1=exp(-h/TAU);
     c2=RESISTANCE*(1-c1);
}

//====================Setters//Getters==================
void Neuron:: setI_ext(double I){Iext_=I;}
/**
 @return current value of External current
 */
double Neuron:: getIext()const {return Iext_;}
/**
 @return current value of Spike time
 */
long Neuron:: getTimeSpike()const { return TimeSpikes_; }
void Neuron:: setMembranePotential(double MP){ MembranePotential_=MP; }
double Neuron:: getMembranePotential()const { return MembranePotential_; }
void Neuron::setBuffer(int indice){Buffer_[indice]+=1;}
long Neuron:: getRefractoryStep()const { return RefractoryStep_; }
long Neuron:: getNbrSpikes()const { return NbSpikes_; }
//====================Convertor==================
std::string Neuron::double_to_string(double c)const{
std::stringstream ss;
ss << c;
std::string str = ss.str();
    return str;
}

//====================Fonctions==================
void Neuron::receive(double nbr_spike){
    MembranePotential_+= (nbr_spike*J);
    
    
}

//====================Update==================
bool Neuron:: update(long steps,long clock){
	
    bool spike(false);
    std::poisson_distribution<> poisson(NU_ext * CE * h * J); // to have NU_extin ms/steps
    
    std::random_device rd;
    std::mt19937 gen(rd());
    
    if(steps<=0) return false;
    
    const long t_stop =tsim_+steps;
    
    while(tsim_<t_stop){
        if(MembranePotential_>THRESHOLD){
            
            ++NbSpikes_;
            TimeSpikes_= tsim_;
            refractory_= true;
            spike=true;
            
        }
        if(refractory_){
            MembranePotential_= 0.0;
            ++RefractoryStep_;
            
             if(RefractoryStep_ > REF_STEPS) {
               RefractoryStep_=0;
               refractory_=false;
               MembranePotential_=VRESET;
            }
  
        }else{
     MembranePotential_= ((c1* MembranePotential_) + (Iext_*c2) + poisson(gen));
     receive(Buffer_[clock%(D+1)]);
     Buffer_[clock%(D+1)]=0;
     }
      ++tsim_;
     
    }
    return spike;
}





