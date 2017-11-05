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

//====================Constructors---Destructors==================

Network :: Network (unsigned int nbr_neurons, long neurones_excit, long neurones_inhib):
NE_(neurones_excit),NI_(neurones_inhib),NbrNeuron_(nbr_neurons),CE_(NE_*0.1),CI_(NI_*0.1),C_EXT(CE_)

{
    for (unsigned int i(0); i< NbrNeuron_ ; ++i ){
        assert(i<NbrNeuron_);
        Neuron N(true);
        Neurons_.push_back(N);
    }
    double Iext (0.0);
    static std::default_random_engine generator;
    static std::uniform_int_distribution<int> distributionCE(0,NE_-1);
    static std::uniform_int_distribution<int> distributionCI(NE_,Neurons_.size()-1);
    
    assert(Neurons_.size()!=0);
    for(size_t i(0); i<Neurons_.size(); i++){
		assert(i<Neurons_.size());
        std::vector<int> j;
        Connections_.push_back(j);
    } 
     
    for(size_t i(0); i<Neurons_.size(); i++){
	assert (i<Neurons_.size());
    Neurons_[i].setI_ext(Iext);
    if(i<NE_){
        Neurons_[i].setJ(JE);
    }else{
        Neurons_[i].setJ(JI);
    }
    unsigned int CompteurCE(0);
    unsigned int CompteurCI(0);
    
    while(CompteurCE<CE_){
        Connections_[distributionCE(generator)].push_back(i);
        ++CompteurCE;
    }

    while(CompteurCI<CI_){
        Connections_[distributionCI(generator)].push_back(i) ;
        ++CompteurCI;
    }
}

}

//====================Setters//Getters==================

std::vector<Neuron> Network ::getNeurons()const{return Neurons_;}
std::vector<std::vector<int> > Network :: getConnections () const{return Connections_;}
long Network:: getNE()const{return NE_;}
long Network:: getNI()const{return NI_;}
long Network:: getCE()const{return CE_;}
long Network:: getCI()const{return CI_;}
long Network:: getNbrNeurons()const{return NbrNeuron_;}
//====================Update==================

void Network :: update( unsigned long t_stop){
    
  std::ofstream sortie("spikes.txt", std::ios::out|std::ios::app);
  bool spike(false);
  unsigned long t(0);
  while(t<t_stop){
      
    //if(Neurons.empty()) //Test si le tableau est vide
      for(size_t i(0);i< Neurons_.size();++i){
        assert(i<Neurons_.size());
        spike=Neurons_[i].update(1);
          
          if (spike){
             sortie<<(Neurons_[i].getTimeSpike())*h<<" "<<i+1<< std:: endl;
               
               for (size_t j(0);j<Connections_[i].size();++j){
					    assert(j<Connections_[i].size());
                        Neurons_[Connections_[i][j]].receive(t,Neurons_[i].getJ());
                }
            }
            spike=false;
        }
        ++t;
    }
    sortie.close();

}
