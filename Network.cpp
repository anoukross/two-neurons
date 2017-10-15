#include "Network.hpp"
#include "Constants.hpp"
#include <iostream>

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
	targets[0].push_back(false); //n0 transmits his spikes to n1
	targets[0].push_back(true);
	targets.emplace_back();
	targets[1].push_back(false);//n1 does not transmit his spikes to n0
	targets[1].push_back(false);
	
	current_weights.emplace_back();
	current_weights[0].push_back(0);//[0][0] ->do not tranfer to himself
	current_weights[0].push_back(0.1); //[0][1] ->0 to 1 with ampiltude 0.1
	current_weights.emplace_back(); 
	current_weights[1].push_back(0.1);//[1][0] ->receives with amplitude 0.1
	current_weights[1].push_back(0); ;//[1][1] ->do not tranfer to himself
	delay.emplace_back();
	delay[0].push_back(0);
	delay[0].push_back(5); //5 steps of time after the Neuron one has spiked will the Neuron 2 receives it
	delay.emplace_back();
	delay[1].push_back(0);
	delay[1].push_back(0);
	
	
}

Network::~Network(){
	for (unsigned int i(0); i<my_network.size(); ++i){
 		delete my_network[i];
		my_network[i]=nullptr;
 	}
	my_network.clear();
}

//Getters
std::vector<Neuron*> Network::getNetwork() const{
	return my_network;
}
std::vector<std::vector<double>> Network::getCurrentWeights() const{
	return current_weights;
}


//Connexion
void Network::connect(unsigned int from, unsigned int to, double weight){
	if((my_network[from]->update(I)) and (targets[from][to])){
		my_network[to]->setIncomingSpikes((delay[from][to]),weight);
		my_network[to]->update(I);
	}
}


