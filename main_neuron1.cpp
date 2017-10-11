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


int main (int argc,char*argv[]){
	
    double I_ext(1.01);
    
    int i_start=1000;// step to start
    int i_stop=4000;// step to stop
    int t_stop=5000;//time to stop
    int nbrNeurons(2);
    int compteur (0);

    //Neuron* n2 = new Neuron;
    std::vector<Neuron*> Neurons_pre;

  while (compteur< nbrNeurons){
      Neurons_pre.push_back(new Neuron);
      ++compteur;
    }
    Neurons_pre[0]->setNeuron_post(Neurons_pre[1]);

    std::ofstream sortie("membrane_potential.txt", std::ios::out|std::ios::app);

    if(argc>1){
        I_ext = atof(argv[1]);
    }
    std::cout << "I_ext=" << I_ext << std::endl;
    
    bool spike(false);
    long t(0);
    while(t<t_stop){
 
        if(Neurons_pre.empty()) return 0;//Test si le tableau est vide     
        for(size_t i(0);i<Neurons_pre.size();++i){
			assert( Neurons_pre[i]!= NULL); // check * neurone pré 
          if((t>=i_start) and (t<=i_stop)){
                Neurons_pre[i]->setI_ext(I_ext);
                spike=Neurons_pre[i]->update(1,t);
                if (spike){
					
                    std::cout << "Spike at t= " << (Neurons_pre[i]->getTimeSpike()+i_start)*h << "ms" << std::endl;
                    if(!Neurons_pre[i]->getNeurons_post().empty()){// check tab
                        
                       for (size_t j(0);j<(Neurons_pre[i]->getNeurons_post()).size();++j){
						 assert( Neurons_pre[i]->getNeurons_post()[j]!= NULL); // check neurone post
						 
						  (Neurons_pre[i]->getNeurons_post()[j])->setBuffer(t%D);
                       }
                    }
                    
                     spike=false;
                  }
            
            }else{
            Neurons_pre[i]->setI_ext(0.0);
        }
        
        sortie<<i<<"...." <<Neurons_pre[i]->double_to_string( Neurons_pre[i]->getMembranePotential())<<std::endl;
       }
       ++t;
    }
       sortie.close();
    
    

    
    return 0;
}


