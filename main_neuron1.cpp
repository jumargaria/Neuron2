//
//  mainN.cpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#include "neuron1.hpp"
#include "constants.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <random>

int main (/*int argc,char*argv[]*/){
    
    double Iext(1.01);
    

    int t_stop=1000;//time to stop
    int const nbrNeurons(12500);
    
    std::vector<Neuron> Neurons(nbrNeurons);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distributionCE(0,NE-1);// static?
    std::uniform_int_distribution<int> distributionCI(NE,Neurons.size()-1);// static?
    assert(Neurons.size()!=0);
    
    
    std::vector<std::vector<int> >Connections(Neurons.size(),std::vector<int>(Neurons.size()));
    for(size_t i(0); i<Neurons.size();++i){
        assert(i<Neurons.size());

		Neurons[i].setI_ext(Iext);
        if(i<10000){
            Neurons[i].setJ(JE);
        }else{
            Neurons[i].setJ(JI);
        }
        unsigned int CompteurCE(1);
        unsigned int CompteurCI(1);

        while(CompteurCE<=CE){
            Connections[i][distributionCE(generator)] += 1;
            ++CompteurCE;
        }
        while(CompteurCI<=CI){
            Connections[i][distributionCI(generator)] += 1;
            ++CompteurCI;
        }
    }
    
    std::ofstream sortie("spikes.txt", std::ios::out|std::ios::app);
    
    bool spike(false);
    long t(0);
    while(t<t_stop){
        
        if(Neurons.empty()) return 0;//Test si le tableau est vide
        for(size_t i(0);i< Neurons.size();++i){
          
                 spike=Neurons[i].update(1);

                if (spike){
                    sortie<<(Neurons[i].getTimeSpike())*h<<" "<<i+1<< std:: endl;
                    std::cout << "Spike of neuron "<<i+1 << " at t= " << (Neurons[i].getTimeSpike())*h << "ms" << std::endl;
                   
                    for (size_t j(0);j<Connections[i].size();++j){
                        if(Connections[j][i]){
							 Neurons[j].receive(t,Connections[i][j]*Neurons[i].getJ());
                        }
                       
                    }
                }
                
                spike=false;
            
    }
    ++t;
}
sortie.close();




return 0;
}


