//
//  mainN.cpp
//  
//
//  Created by Juliette Margaria on 02/10/2017.
//
//

#include "neuron1.hpp"
#include "Network.hpp"
#include "constants.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <random>

int main (){

    int t_stop=10000;//time to stop
    int const nbrNeurons(12500);
    
    Network Net(nbrNeurons,NE,NI);
    Net.update(t_stop);

return 0;
}


