//
//  Network.cpp
//  
//
//  Created by Juliette Margaria on 30/10/2017.
//
//

#include "Network.hpp"
#include "constants.hpp"
#include <random>
Network :: Network (unsigned int nbr_neurons, long neurones_excit, long neurones_inhib):
NE_(NE),NI_(NI),NbrNeuron_(nbr_neurons)
{
    
    for (unsigned int i(0); i< NbrNeuron_ ; ++i ){
        Neuron N;
        Neurons_.push_back(N);
    }
    double Iext (0.0);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distributionCE(0,NE-1);// static?
    std::uniform_int_distribution<int> distributionCI(NE,Neurons_.size()-1);// static?
    
     assert(Neurons_.size()!=0);
    for(size_t i(0); i<Neurons_.size();++i){
    assert(i<Neurons_.size());
    for(size_t i(0); i<Neurons_.size(); i++){
        std::vector<int> j(NbrNeuron_);
        fill(j.begin(),j.begin()+NbrNeuron_,0);
        Connections_.push_back(j);
    } 
    
    Neurons_[i].setI_ext(Iext);
    if(i<10000){
        Neurons_[i].setJ(JE);
    }else{
        Neurons_[i].setJ(JI);
    }
    unsigned int CompteurCE(1);
    unsigned int CompteurCI(1);
    
    while(CompteurCE<=CE){
        Connections_[i][distributionCE(generator)] += 1;
        ++CompteurCE;
    }
    while(CompteurCI<=CI){
        Connections_[i][distributionCI(generator)] += 1;
        ++CompteurCI;
    }
}
}
void Network :: update( long t_stop){
    
    std::ofstream sortie("spikes.txt", std::ios::out|std::ios::app);
    
    bool spike(false);
    long t(0);
    while(t<t_stop){
        
        //if(Neurons.empty()) //Test si le tableau est vide
        for(size_t i(0);i< Neurons_.size();++i){
            
            spike=Neurons_[i].update(1);
            
            if (spike){
                sortie<<(Neurons_[i].getTimeSpike())*h<<" "<<i+1<< std:: endl;
               
                for (size_t j(0);j<Connections_[i].size();++j){
                    if(Connections_[j][i]){
                        Neurons_[j].receive(t,Connections_[i][j]*Neurons_[i].getJ());
                    }
                    
                }
            }
            
            spike=false;
            
        }
        ++t;
    }
    sortie.close();
    

}
