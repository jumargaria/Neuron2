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
    int i_start=1000;//a
    int i_stop=4000;//b
    int t_stop=5000;
    
    
    Neuron n;
    Neuron n2;
    std::vector<Neuron> Neurons_pre (1,n);
    std::vector<Neuron*>N(1,{*n2});
    n.setNeurons_post(N);
    std::ofstream sortie("membrane_potential.txt", std::ios::out|std::ios::app);

    if(argc>1){
        I_ext = atof(argv[1]);
    }
    
    std::cout << "I_ext=" << I_ext << std::endl;
    
    bool spike(false);
    long t(0);
    while(t<t_stop){
        if(Neurons_pre.empty()) return 0;
        for(unsigned i(0);i<Neurons_pre.size();++i){
        if((t>=i_start) and (t<=i_stop)){
               // if(Neurons_pre[i]!=nullptr)
                Neurons_pre[i].setI_ext(I_ext);
                spike=Neurons_pre[i].update(1);//update h???
                if (spike){
                    std::cout << "Spike at t= " << (Neurons_pre[i].getTimeSpike()+i_start)*h << "ms" << std::endl;
                    spike=false;//??
                    for (unsigned j(0);j<Neurons_pre[i].getNeurons_post().size();++i){
                        (Neurons_pre[i].getNeurons_post()[j])->receive(Neurons_pre[i].getTimeSpike(),J);
                            std::cout<<"Hello:"<<std::cout<<(Neurons_pre[i].getNeurons_post()[j])->getMembranePotential()<<std::endl;
                    
                    }
                }
            
        }else{
            Neurons_pre[i].setI_ext(0.0);
        }
       }
       ++t;
        sortie<< n.double_to_string( n.getMembranePotential())<<std::endl;
    }
       sortie.close();
    
    
    
   /*
    Neuron n2;
   
    vector<Neuron> Neurons_pre (1,{n});
    vector<Neuron*>Neurons_post(1, {n2});// ca je le veux pour chaque neurone => attribut ?
    
    while(tsim_<t_stop){
       for(unsigned i(0);i<Neurons_pre.size();++i){
        spike=Neurons_pre[i].update(1);//update h???
          if (spike) {
            for (unsigned j(0);j<Neurons_post.size();++i){
                *Neurons_post[j].receive(Neurons_pre[i].getTimeSpike(),J);
            }
          }
       }
    }*/
    
    
    return 0;
}


