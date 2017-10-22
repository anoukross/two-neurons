# two-neurons
The Neuron project - S2
This week we have been working on implementing the connexion of two neurons. Whenever n0(neuron 0) spikes it transmits a current J with a delay D(15 -> 1.5 ms) to the neuron n1. 
I created a class Network containg all of my neurons, their relations with one another (whether nx is the target of ny), the current weight they transmit to one another and the delay of these transmissons. 
The Network class contains a method connect(unsigned int from, unsigned int to, double weight) which updates the current of n(to) if n(from) has spiked. The contribution of n(from) to n(to) happens with a delay D. This contribution is equal to the smallest among the weight n(from) can give to n(to) and the weight that n(to) can receive from n(from).This is checked in the main. 
The delay is implemented with a ring buffer. In my class Neuron, I have an attribute std::array<int, Dmax> incoming_spikes; where Dmax is the biggest delay existing + 1. When n(from) spikes, my program checks the delay of transmission between n(from) and n(to) and adds the weight of the current  to the corresponding box - > incoming_spikes[(delay+clock)%Dmax]+=weight;
This permits not to have an infinit incoming_spikes tab.   
When calculating, the mebrane potential, the method update verifies whether a postsynaptic current is associated with the current time, that is to say if incoming_spikes[clock%Dmax]>0.0. If it is, the new potential is recalculated by adding the value J of the postsynaptic current.
