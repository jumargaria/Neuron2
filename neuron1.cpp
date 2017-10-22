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
Neuron:: Neuron():MembranePotential_(0.0),NbSpikes_(0.0),TimeSpikes_(0.0),refractory_(false), RefractoryStep_(0.0),tsim_(0.0),Iext_(0.0) {
    
    for(size_t i(0);i<(D+1);++i){
        Buffer_.push_back(0.0);
    }
  c1=exp(-h/TAU);
  c2=RESISTANCE*(1-c1);
}

//====================Setters//Getters==================
void Neuron:: setI_ext(double I){Iext_=I;}
double Neuron:: getIext()const {return Iext_;}
long Neuron:: getTimeSpike()const { return TimeSpikes_; }
void Neuron:: setMembranePotential(double MP){ MembranePotential_=MP; }
double Neuron:: getMembranePotential()const { return MembranePotential_; }
void Neuron::setBuffer(int indice){Buffer_[indice]+=1;}
//====================Convertor==================
std::string Neuron::double_to_string(double c)const{
std::stringstream ss;
ss << c;
std::string str = ss.str();
    return str;
}

//====================Functions==================
void Neuron::receive(double nbr_spike){
    MembranePotential_+= (nbr_spike*J);
    
    
}

//====================Update==================
bool Neuron:: update(long steps,long clock){
    bool spike(false);
    if(steps<=0) return false;//test if the number of steps is correctly enter
    
    const long t_stop =tsim_+steps;
    
    while(tsim_<t_stop){
        
        if(MembranePotential_>THRESHOLD){// test if the membrane potential is above the threshold
            spike=true; // then the neurone spike
            ++NbSpikes_; // increase the number of spike
            TimeSpikes_= tsim_; // update last time spike
            refractory_= true; // when the neuron has spike the neurone get refractory
            
        }
        if(refractory_){
            MembranePotential_= 0.0; // the membane potential is equal to 0.0 during the refractory time
            ++RefractoryStep_;
            
             if(RefractoryStep_ > REF_STEPS) { // then the neurone is not refractory
               refractory_=false;
               RefractoryStep_=0;
               MembranePotential_=VRESET; // the membrane potential is equal to Vreset ( a defined constant) just after the refractory time
            }
  
        }else{
     MembranePotential_= (c1* MembranePotential_)+ (Iext_*c2); // we increase the membrane potential
     receive(Buffer_[clock%(D+1)]); // allows to receive J times the number in Buffer_[clock%(D+1)
     Buffer_[clock%(D+1)]=0; // we update the buffer
     }
      ++tsim_;
     
    }
    return spike; // return true if the neurone has spike
}





