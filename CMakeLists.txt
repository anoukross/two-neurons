cmake_minimum_required (VERSION 2.6)
project (Neuron)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")
add_executable (Neuron Constants.hpp Neuron.hpp Neuron.cpp Network.hpp Network.cpp main.cpp)
