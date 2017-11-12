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
Neuron:: Neuron():MembranePotential_(0.0),NbSpikes_(0.0),TimeSpikes_(0.0),refractory_(false), RefractoryStep_(0.0),tsim_(0.0),Iext_(1.01),J(JE){
    for(size_t i(0);i<(DELAY+1);++i){
        Buffer_.push_back(0.0);
    }
        c1=exp(-h/TAU);
     c2=RESISTANCE*(1-c1);
}

//====================Setters//Getters==================
/**
 * Getter for external current
 @return current value of External current
 */
double Neuron:: getIext()const {return Iext_;}
/**
 * Getter for Time Spike
 @return current value of Spike time
 */
long Neuron:: getTimeSpike()const { return TimeSpikes_; }
/**
 * Getter for Refractory Step ??
 @return current value of RefractoryStep
 */
long Neuron:: getRefractoryStep()const { return RefractoryStep_; }
/**
 * Getter for Number of spike
 @return current value of Number of spike
 */
long Neuron:: getNbrSpikes()const { return NbSpikes_; }
/**
 * Getter for J
 @return current value of J
 */
double Neuron::getJ()const{return J;}
/**
 * Getter for Membrane potential
 @return current value of Membrane Potential
 */
double Neuron:: getMembranePotential()const { return MembranePotential_; }
/**
 Set Membrane Potential
 @param MP: Membrane potential
 */
void Neuron:: setMembranePotential(double MP){ MembranePotential_=MP; }
// besoin?
void Neuron::setBuffer(int indice){Buffer_[indice]+=1;}
/**
 Set external current
 @param i_ext: external current
 */
void Neuron:: setI_ext(double I){Iext_=I;}
/**
 Set J
 @param j: weight of the connection in mV
 */
void Neuron::setJ( double j){J=j;}
//====================Convertor==================
/**
 Convert a double into a string
 @param c: the double to convert
 @return c in string
 */
std::string Neuron::double_to_string(double c)const{
std::stringstream ss;
ss << c;
std::string str = ss.str();
    return str;
}

//====================Fonctions==================
/**
 Receive a sike a time arrival with height j.
 If more than one spike arrives at the same time, j is the sum of ...
 @param arrival: time in step at which the spike arrives
 @param j: weight of the connection in mV
 */
void Neuron::receive(unsigned long arrival, double j){
    const size_t time = arrival%(DELAY+1);
    assert (time<Buffer_.size());
    Buffer_[time]+=j;
}

//====================Update==================
/**
 update the state of the neurone each time t
 @param steps: number of simulation steps
 */
bool Neuron:: update(long steps){
	
    bool spike(false);
    double lambda (NU_ext* h);
    assert ((lambda <3) and (lambda >1));
    static std::poisson_distribution<> poisson(lambda); // to have NU_ext in ms/steps
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    if(steps<=0) return false;
    
    const long t_stop =tsim_+steps;
    const auto t_in= tsim_%(DELAY+1);
    
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
     MembranePotential_= ((c1* MembranePotential_) + (Iext_*c2)
                          + Buffer_[t_in]+ poisson(gen)*JE);
                          
     Buffer_[t_in]=0;
     }
      ++tsim_;
     
    }
    return spike;
}





