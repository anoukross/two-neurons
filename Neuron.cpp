#include "Neuron.hpp"
#include <cmath>
#include "Network.hpp"
#include <iostream>
#include <cassert>

//Constructeur et destructeur
Neuron::Neuron(unsigned int i, double potential)
:indice(i), V(potential), spikesNumber(0.0), refractory_time(0), clock(0)
{
	for(unsigned int i(0);i<Dmax;++i){
		incoming_spikes[0]=0.0;
	}
	
	spikesTime.clear(); //To be sure that when we create a neuron it has got no spikes time 
}
Neuron::~Neuron(){}
		
//Getters
double Neuron::getPotential() const{
	return V;
}
double Neuron::getResistance() const{
	return R;
}
unsigned int Neuron::getSpikesNumber() const{
	return spikesNumber;
}
std::vector<double> Neuron::getSpikesTime() const{
	return spikesTime;
}

//Setters
void Neuron::setPotential(double potential){
	V=potential;
}
void Neuron::setIncomingSpikes(unsigned int delay, double weight){
	unsigned int t_spike = (delay+clock)%Dmax;
	assert(t_spike < incoming_spikes.size());
	incoming_spikes[t_spike]+=weight; //Ww add the weight of the postsynaptic current in the buffer compartment corresponding to (delay+clock)%Dmax
}

//bool
bool Neuron::isRefractory(){
	if(refractory_time> 0.0){
	return true;
	}
	return false;
}

		
//Update
bool Neuron::update(double I, unsigned int time){
	bool hasSpiked(false);
	if(isRefractory()){ //If neuron is refractory -> neuron has spiked -> V is not modified
		refractory_time-=step;//Decrementation of the refractory time
	}else{
		double V_new(c1*V+I*c2);
		if(incoming_spikes[clock%Dmax]>0.0){ //If a spike is associated with the current time, we add it to the new potential
			V_new+=incoming_spikes[clock%Dmax];
			std::cout << "Neuron " << indice+1 << " has received a spike at time " << time*h << std::endl;	
			incoming_spikes[clock%Dmax]=0.0; //Reinitialisation of the value of my buffer corresponding to [clock%Dmax[ that have just been used
		}
			
		if(V_new > V_th){
			spikesTime.push_back(clock); 
			spikesNumber+=1;
			refractory_time=tau_ref/h; //Initialisation of the refractory time 
			V_new=V_reset; //After  a spike, the potential gets back to its reset value	
			hasSpiked=true;	
			std::cout << "Neuron " << indice+1 << " has spiked at time: " << time*h << std::endl;
			}
		
		V=V_new; //modify neuron potential
	}
	
	
	++clock;
		
	return hasSpiked;
}
