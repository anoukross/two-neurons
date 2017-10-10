#include "Network.hpp"
#include <memory>

//Constructeur et destructeur

Network::Network()
{
	
	
	std::unique_ptr<Neuron> n0(new Neuron(0));
	std::unique_ptr<Neuron> n1(new Neuron(1));
	
	my_network.push_back(n0);
	my_network.push_back(n1);
	neighbours.emplace_back();
	neighbours[0].push_back(true); //n0 transmits his spikes to n1
	neighbours.emplace_back();
	neighbours[1].push_back(false);//n1 does not transmit his spikes to n0
	
	
}

Network::~Network(){}

//Getters
std::vector<std::unique_ptr<Neuron>> Network::getNetwork(){
	return my_network;
}

unsigned int Network::getNetworkSize(){
	return my_network.size();
}


//Connexion
void Network::connect(unsigned int from, unsigned int to, double weight, double current){
	if(neighbours[from][to]==true){
		double V_post_synap(weight + my_network[to].getPotential());
		my_network[to].update(current, V_post_synap);
	}
}

