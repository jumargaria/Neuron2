//
//  Network.cpp
//  
//
//  Created by Juliette Margaria on 30/10/2017.
//
//

#include "Network.hpp"


#include <random>

//====================Constructors---Destructors==================

Network :: Network () 
{
    for (unsigned int i(0); i< NbrNeuron ; ++i ){
        assert(i<NbrNeuron);
        Neuron N(true);
        Neurons_.push_back(N);
    }
    double Iext (0.0);
    static std::default_random_engine generator;
    static std::uniform_int_distribution<unsigned int> distributionCE(0,NE-1);
    static std::uniform_int_distribution<unsigned int> distributionCI(NE,Neurons_.size()-1);
    
    assert(Neurons_.size()!=0);
<<<<<<< HEAD
    for(size_t i(0); i<Neurons_.size(); i++){
=======
   // std::vector<std::vector<unsigned int> >Connections_ (NbrNeuron, std::vector<unsigned int>subvector );
    for(size_t i(0); i<Neurons_.size(); i++){
		assert(i<Neurons_.size());
>>>>>>> 4272d06dbac65653125863db7420ad3f83fbb81d
        std::vector<unsigned int> subvector;
        Connections_.push_back(subvector);
    } 
     
    for(size_t i(0); i<Neurons_.size(); i++){
	assert (i<Neurons_.size());
    Neurons_[i].setI_ext(Iext);
    if(i<NE){
        Neurons_[i].setJ(JE);
    }else{
       Neurons_[i].setJ(JI);
    }
    unsigned int CompteurCE(0);
    unsigned int CompteurCI(0);
    
    while(CompteurCE<CE){
        Connections_[distributionCE(generator)].push_back(i);
        ++CompteurCE;
    }

    while(CompteurCI<CI){
        Connections_[distributionCI(generator)].push_back(i) ;
        ++CompteurCI;
    }
}

}

//====================Setters//Getters==================

std::vector<Neuron> Network ::getNeurons()const{return Neurons_;}
std::vector<std::vector<unsigned int> > Network :: getConnections()const {return Connections_;}

//====================Update==================

void Network :: update( unsigned long t_stop){
    
  std::ofstream sortie("spikes.txt", std::ios::out|std::ios::app);
  unsigned long t(0);
  while(t<t_stop){
      
    if(! Neurons_.empty()){
      for(size_t i(0); i<Neurons_.size(); ++i){
		 
          
          if (Neurons_[i].update(1)){
<<<<<<< HEAD
             sortie<<(Neurons_[i].getTimeSpike())*h*0.01<<" "<<i+1<< std:: endl;
=======
             sortie<<(Neurons_[i].getTimeSpike())*h<<" "<<i+1<< std:: endl;
>>>>>>> 4272d06dbac65653125863db7420ad3f83fbb81d
               
               for (size_t j(0);j<Connections_[i].size();++j){
                        Neurons_[Connections_[i][j]].receive(t,Neurons_[i].getJ());
                }
            }
        }
        ++t;
    }
  }
 sortie.close();
}
