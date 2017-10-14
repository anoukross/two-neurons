#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	
	Network net;
	
	/*cout << "Specify an external current (I=[0,400 pA]) : ";
	cin >> I;
	cout << endl;*/
	
	double startTime(0.0);
	double stopTime(0.0);
	

	cout << "Choose the stop time: ";
	cin >> stopTime;
	cout << endl;
	
	
	ofstream out("simulator.txt");
	int steps_number(stopTime/Neuron::h); //Division by h to get a integer  
	
	for(unsigned int i(0); i<net.getNetwork().size();++i){
	
		for(double t(startTime/Neuron::h); t<steps_number; t+=1){
			if (out.fail()){
				cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
				<< "en écriture." << endl;
			} else {
				for(unsigned int i(0); i<net.getNetwork().size(); ++i){
					for(unsigned int j(0); j<net.getNetwork().size(); ++j){
						if(i!=j){
							net.connect(i,j, Neuron::J);
						}
						
					}
					out << "A temps: " << t*Neuron::h << " ms, le potentiel de membrane du neurone " << i+1 <<  " est: " << net.getNetwork()[i]->getPotential() << "." << endl;
						
				}
			}
		}
	}
	
	return 0;
	
}
