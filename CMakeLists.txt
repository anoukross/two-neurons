cmake_minimum_required (VERSION 2.6)
project (Test1)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")
add_executable (Test1 Constants.hpp Neuron.hpp Neuron.cpp Network.hpp Network.cpp Test1.cpp)
