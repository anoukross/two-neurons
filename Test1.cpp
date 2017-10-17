#include "Neuron.hpp"
#include "googletest/include/gtest/gtest.h"
#include <cmath>


TEST (NeuronTest, shouldNotSpike){
	Neuron n(0);
	double I(1.0);
	
	for(unsigned int t(0); t<5000;  ++t){ //t corresponds to the step of time 5000 ->500 ms
		EXPECT_EQ(n.update(I,t),false); //should never spike when the current is 1.0
		EXPECT_LE(n.getPotential(),20); //The potential should never go above the Vthreshold=20
	}	
}

TEST (NeuronTest, shouldSpike){
	Neuron n(0);
	double I(1.01);
	
	for(unsigned int t(0); t<5000;  ++t){ //t corresponds to the step of time 5000 ->500 ms
		
		//Should spike only at 92.4ms, 186.8ms,281.2ms,375.6ms, 470.0ms
		if((abs(92.3/Neuron::h-t) <= exp(-6)) or (abs(186.7/Neuron::h-t) <= exp(-6)) or (abs(281.1/Neuron::h-t) <= exp(-6)) or (abs(375.5/Neuron::h-t) <= exp(-6)) or (abs(469.9/Neuron::h-t) <= exp(-6))){
			EXPECT_EQ(n.update(I,t),true); 
		}else{
			EXPECT_EQ(n.update(I,t),false); 
		}
	}	
}


