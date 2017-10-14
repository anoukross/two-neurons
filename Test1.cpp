#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>

int main(){
	
	Network net;
	double weight(10);
	std::cout << "Le potentiel du neurone 2 avant le spike du neurone 1 est de" << net.getNetwork()[1]->getPotential() << std::endl;
	net.getNetwork()[0]->setPotential(20.1);
	net.connect(0,1, weight);
	std::cout << "Le potentiel du neurone 2 après le spike du neurone 1 est de" << net.getNetwork()[1]->getPotential() << std::endl;
	
	return 0;
}
