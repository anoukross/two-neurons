#include "Network.hpp"
#include "googletest/include/gtest/gtest.h"
#include <cmath>

//Before delay
/*TEST (NetworkTest, VmatchesJ){
	Network net;
	double I(1.01);
	for(unsigned int t(0); t<1000;  ++t){ //t corresponds to the step of time 5000 ->500 ms
		//At 92.4ms (t=924 the potential of n2 should have increased of net.getCurrentWeights()[i][j]=0.1
		if(t==924){
		double potential(net.getNetwork()[1]->getPotential()); //Potential befor that n0 has spiked
		net.connect(0,1,I,net.getCurrentWeights()[0][1], t);
		EXPECT_LE((abs(potential + 0.1- (net.getNetwork()[1]->getPotential()))), exp(-6)); //Expect equality of double less or equal than exp(-6)	
		}
	}	
	
}*/

TEST (NetworkTest, VmatchesD){
	Network net;
	double I(1.01);
	for(unsigned int t(0); t<1000;  ++t){ //t corresponds to the step of time 5000 ->500 ms
		//At 92.4ms+1.5 ms=93.9 (t=924+15=939 the potential of n2 should have increased of net.getCurrentWeights()[i][j]=0.1
		if(t<937){
			double potential(net.getNetwork()[1]->getPotential()); 
			net.connect(0,1,I,net.getCurrentWeights()[0][1], t);
			net.connect(1,0,0, net.getCurrentWeights()[0][1], t);
			EXPECT_LE((abs(potential - net.getNetwork()[1]->getPotential())), exp(-6)); //potential should be the same after connect -> delay is not over
																					//Expect equality of double less or equal than exp(-6)		
		}	
		if(t==937){
			double potential(net.getNetwork()[1]->getPotential()); 
			net.connect(0,1,I,net.getCurrentWeights()[0][1], t);
			EXPECT_LE((abs(potential + 0.1 - net.getNetwork()[1]->getPotential())), exp(-6)); //potential corresponds to the potential before the end of the delay  	
																//net.getNetwork()[1]->getPotential() is after receiving the amplitude J(0.1)
																//So potential + J should = net.getNetwork()[1]->getPotential()
			net.connect(1,0,0,net.getCurrentWeights()[0][1], t);													
		}														
	}	
}

