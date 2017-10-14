#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include <vector>
#include <memory>


class Network{
	private:
		//std::vector<std::unique_ptr<Neuron>> my_network; 
		std::vector<Neuron*> my_network; 
		std::vector<std::vector<bool>> neighbours; 
		std::vector<std::vector<double>> current_weights; 
	public:
	
	//Constructeur et destructeur
		Network();
		~Network();
		
	//Getters
	std::vector<Neuron*> getNetwork();
		
	//Connexion
	void connect(unsigned int from, unsigned int to, double J, double current);
	
};

#endif
