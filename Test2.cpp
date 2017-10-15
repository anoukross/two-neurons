#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>

int main(){
	
	//5 step of time of delay -> we should have a drastic increase of the second neuron potenial after 5 step of time
	Network net;
	double weight(10);
	std::cout << "0. Le potentiel du neurone 2 avant le spike du neurone 1 est de" << net.getNetwork()[1]->getPotential() << std::endl;
	net.getNetwork()[0]->setPotential(20.1);
	net.connect(0,1, weight);
	net.connect(1,0,0);
	for(unsigned int i(0);i<5;++i){
		std::cout << i+1 << ". Le potentiel du neurone 2 après le spike du neurone 1 est de" << net.getNetwork()[1]->getPotential() << std::endl;
		net.connect(0,1, 0);
		net.connect(1,0,0);
		}
	
	return 0;
}
