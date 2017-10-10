#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Neuron.hpp"
#include <vector>
#include <memory>


class Network{
	private:
		std::vector<std::unique_ptr<Neuron>> my_network; 
		std::vector<std::vector<bool>> neighbours; 
		std::vector<std::vector<double>> current_weights; 
	public:
	
	//Constructeur et destructeur
		Network();
		~Network();
		
	//Getters
	std::vector<std::unique_ptr<Neuron>> getNetwork();
	static unsigned int getNetworkSize();
		
	//Connexion
	static void connect(unsigned int from, unsigned int to, double weight, double current);
	
};

#endif
