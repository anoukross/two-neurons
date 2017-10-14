#include "Neuron.hpp"
#include <cmath>
#include "Network.hpp"

//Constructeur et destructeur
Neuron::Neuron(double potential)
:V(potential), spikesNumber(0.0), refractory_time(0), clock(0)
{
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
double Neuron::getPostSynaptic() const{
	return J;
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

//bool
bool Neuron::isRefractory(){
	if(refractory_time> 0.0){
	return true;
	}
	return false;
}

		
//Update
bool Neuron::update(double I, double weight){
	bool hasSpiked(false);
	if(isRefractory()){ //If neuron is refractory -> neuron has spiked -> V is not modified
		refractory_time-=step;//Decrementation of the refractory time 
	}else{
		double V_new(e*V+I*R*(1-e) + weight);
			
		if(V_new > V_th){
			spikesTime.push_back(clock); 
			spikesNumber+=1;
			refractory_time=tau_ref/h; //Initialisation of the refractory time 
			V_new=V_reset; //After  a spike, the potential gets back to its reset value	
			hasSpiked=true;	
			}
		
		V=V_new; //modify neuron potential
	}
	
	
	++clock;	
	return hasSpiked;
}
