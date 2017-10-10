#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include <vector>


class Network{
	private:
		std::vector<unsigned int> my_network; //Index of the neurons
		std::vector<std::vector<bool>> neighbours; 
		std::vector<std::vector<double>> current_weights; 
	public:
	
	//Constructeur et destructeur
		Network();
		~Network();
		
	//Getters
	std::vector<unsigned int> getMyNetwork();
		
	//Connexion
	void connect(unsigned int from, unsigned int to, double weight);
	
};

#endif
