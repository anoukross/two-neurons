project (Neuron)
cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (Neuron Neuron.hpp Neuron.cpp Network.hpp Network.cpp main.cpp)
add_executable (Neuron_unittest Neuron.cpp Test1.cpp Testmain.cpp)
add_executable (Network_unittest Neuron.cpp Network.cpp Tests2.cpp Tests2main.cpp)

target_link_libraries(Neuron_unittest gtest gtest_main)
add_test(Neuron_unittest Neuron_unittest)

target_link_libraries(Network_unittest gtest gtest_main)
add_test(Network_unittest Network_unittest)

 
