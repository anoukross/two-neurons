#include "Neuron.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	
	vector<Neuron> n(2); //Creates 2 neurons
	
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
	
	for(unsigned int i(0); i<n.size();++i){
	
		for(double t(startTime/Neuron::h); t<steps_number; t+=1){
			if (out.fail()){
				cerr << "Erreur : impossible d'ouvrir le fichier " << "simulator.dat"
				<< "en écriture." << endl;
			} else {
				out << "A temps: " << t*Neuron::h << " ms, le potentiel de membrane du neurone " << i+1 <<  " est: " << n[i].getPotential() << "." << endl;
					
					

			}
	
			n[i].update(I);	
			
		}
	}
	
	return 0;
	
}
