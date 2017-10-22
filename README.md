# two-neurons
The Neuron project - S2/S3

Test 1 consists of two tests: shouldNotSpike and shouldSpike. The first one tests the program with an external current of 1.0pA -> this current should not be sufficient for spiking, thus the membrane potential should be always smaller than the potential threshold(20mV). -> works 
The second one verifies the time at which the spikes occur when giving an external current of 1.01pA. If the start time=0.0 ms and the stop time 500.0 ms ,the neuron should spike only at 92.4ms, 186.8ms,281.2ms,375.6ms and 470.0ms. (Thus, update which returns whether the neuron has spiked or not should be true only for this values). I have 0.1ms of advance for each spikes. 
