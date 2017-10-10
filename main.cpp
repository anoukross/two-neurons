#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	
	Network net;

	
	double I(0); //I = external current
	
	cout << "Specify an external current (I=[0,400 pA]) : ";
	cin >> I;
	cout << endl;
	
	double startTime(0.0);
	double stopTime(0.0);
	

	cout << "Choose the stop time: ";
	cin >> stopTime;
	cout << endl;
	
	
	ofstream out("simulator.txt");
	int steps_number(stopTime/Neuron::h); //Division by h to get a integer  
	
	for(unsigned int i(0); i<net.getNetworkSize();++i){
	
		for(double t(startTime/Neuron::h); t<steps_number; t+=1){
			if (out.fail()){
				cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
				<< "en écriture." << endl;
			} else {
					out << "A temps: " << t*Neuron::h << " ms, le potentiel de membrane du neurone " << i+1 <<  " est: " << net.getNetwork()[i]->getPotential() << "." << endl;
						
			}
	
			net.getNetwork()[i]->update(I, net.getNetwork()[i]->getPotential());	
			
		}
	}
	
	return 0;
	
}
