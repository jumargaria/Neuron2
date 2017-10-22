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
    
    // ===============constants==========================
    double I_ext(1.01);
    int i_start=1000;// step to start
    int i_stop=4000;// step to stop
    int t_stop=5000;//time to stop
    int nbrNeurons(2);
    
    std::vector<Neuron> Neurons(nbrNeurons);// vector representing the network with all the neurons
    std::vector<std::vector<bool> >Connections(Neurons.size(),std::vector<bool>(Neurons.size()));// vector of boolean which simulate the connections ( e.g. return true in Connections[1][2] if the neurone 1 is connected with the neuron 2)
    
 // ==================simulation==========================
    //
    for(size_t i(0); i<Neurons.size();++i){
        for(size_t j(0);j<Neurons.size();++j){
            Connections[i][j]=false;
        }
    }
    Connections[0][1]=true;
    // allows the simulator to choose Iext , by default Iext= 1.01
    std::ofstream sortie("membrane_potential.txt", std::ios::out|std::ios::app);
    
    if(argc>1){
        I_ext = atof(argv[1]);
    }
    std::cout << "I_ext=" << I_ext << std::endl;
    
    
    bool spike(false);
    long t(0);
    while(t<t_stop){
        
        if(Neurons.empty()) return 0;//Test if there is no neurons => do nothing
        
        for(size_t i(0);i<Neurons.size();++i){
            if((t>=i_start) and (t<=i_stop)){
				if(i==0){
                Neurons[i].setI_ext(I_ext);
                }else{
                Neurons[i].setI_ext(0.0);
                }
                spike=Neurons[i].update(1,t);
                
                if (spike){
                    
                    std::cout << "Spike of neuron "<<i+1 << " at t= " << (Neurons[i].getTimeSpike()+i_start)*h << "ms" << std::endl;
                    
                    for (size_t j(0);j<Connections[i].size();++j){
                        if(Connections[i][j]){
							 Neurons[j].setBuffer(t%(D+1));
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


