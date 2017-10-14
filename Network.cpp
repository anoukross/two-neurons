#include "Network.hpp"


//Constructeur et destructeur

Network::Network()
{
	
	
	//std::unique_ptr<Neuron> n0(new Neuron(0));
	//std::unique_ptr<Neuron> n1(new Neuron(1));
	
	
	Neuron* n0(nullptr);
	n0= new Neuron(0);
	
	Neuron* n1(nullptr);
	n1= new Neuron(1);
	
	my_network.push_back(n0);
	my_network.push_back(n1);
	neighbours.emplace_back();
	neighbours[0].push_back(true); //n0 transmits his spikes to n1
	neighbours.emplace_back();
	neighbours[1].push_back(false);//n1 does not transmit his spikes to n0
	
	
}

Network::~Network(){
	for (unsigned int i(0); i<my_network.size(); ++i){
		delete my_network[i];
		my_network[i]=nullptr;
	}
	my_network.clear();
}

//Getters
std::vector<Neuron*> Network::getNetwork(){
	return my_network;
}


//Connexion
void Network::connect(unsigned int from, unsigned int to, double J, double current){
	if(neighbours[from][to]==true){
		my_network[to]->update(current, J);
	}
}

