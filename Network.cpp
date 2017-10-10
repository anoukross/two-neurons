#include "Network.hpp"

//Constructeur et destructeur

Network::Network()
{
	Neuron n0(0);
	Neuron n1(1);
	
	my_network.push_back(0);
	my_network.push_back(1);
	neighbours.emplace_back();
	neighbours[0].push_back(true); //n0 transmits his spikes to n1
	neighbours.emplace_back();
	neighbours[1].push_back(false);//n1 does not transmit his spikes to n0
	
	
}

Network::~Network(){}



//Connexion
void Network::connect(unsigned int from, unsigned int to, double weight){
	if(neighbours[from][to]==true){
		double V_post_synap(e*weight+I*R*(1-e)+);
		
		to.update(
	}
}

