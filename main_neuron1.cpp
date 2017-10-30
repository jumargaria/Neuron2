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
    
    int i_start=1000;// step to start
    int i_stop=4000;// step to stop
    int t_stop=5000;//time to stop
    int const nbrNeurons(12500);
    
    std::vector<Neuron> Neurons(nbrNeurons);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distributionCE(0,NE-1);
    std::uniform_int_distribution<int> distributionCI(NE,Neurons.size()-1);
    assert(Neurons.size()!=0);
    
    
    std::vector<std::vector<int> >Connections(Neurons.size(),std::vector<int>(Neurons.size()));
    for(size_t i(0); i<3;++i){
		std::cout << "I_ext=" << Neurons[i].getIext() << std::endl;
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
    
    std::ofstream sortie("membrane_potential.txt", std::ios::out|std::ios::app);
    
   
   // std::cout << "I_ext=" << I_ext << std::endl;
    
    bool spike(false);
    long t(0);
    while(t<t_stop){
        
        if(Neurons.empty()) return 0;//Test si le tableau est vide
        for(size_t i(0);i<2;++i){
            if((t>=i_start) and (t<=i_stop)){
				std::cout << "Iext  "<<Neurons[i].getIext()<< std::endl;
                 spike=Neurons[i].update(1);
                //std::cout << "MP "<< i+1<< "  "<<Neurons[i].getMembranePotential()<< std::endl;
                if (spike){
                    
                    std::cout << "Spike of neuron "<<i+1 << " at t= " << (Neurons[i].getTimeSpike()+i_start)*h << "ms" << std::endl;
                   // std::cout << "Number of spike "<< i+1<<Neurons[i].getNbrSpikes()<< std::endl;
                    for (size_t j(0);j<Connections[i].size();++j){
                        if(Connections[i][j]){
							 Neurons[j].receive(t,Connections[i][j]*Neurons[i].getJ());
                        }
                       
                    }
                }
                
                spike=false;
            
            
        }else{
            Neurons[i].setI_ext(0.0);
        }
        
        sortie<<i<<"...." <<Neurons[i].double_to_string( Neurons[i].getMembranePotential())<<std::endl;
    }
    ++t;
}
sortie.close();




return 0;
}


