#include "Network.hpp"
#include "Constants.hpp"


//Constructeur et destructeur

Network::Network()
{
	
	
	Neuron* n0(nullptr);
	n0 = new Neuron;
	
	Neuron* n1(nullptr);
	n1 = new Neuron;
	n1->setPotential(-20);
	
	my_network.push_back(n0);
	my_network.push_back(n1);
	targets.emplace_back(); 
	targets[0].push_back(true); //n0 transmits his spikes to n1
	targets.emplace_back();
	targets[1].push_back(false);//n1 does not transmit his spikes to n0
	
	
}

Network::~Network(){}

//Getters
std::vector<Neuron*> Network::getNetwork(){
	return my_network;
}


//Connexion

void Network::connect(unsigned int from, unsigned int to, double weight){
	if( my_network[from]->update(I, 0) and targets[from][to]==true){
		my_network[to]->update(I, weight);
	}
}


