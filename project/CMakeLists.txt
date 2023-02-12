cmake_minimum_required(VERSION 3.8)

project(test CXX)

add_executable(test src/main.cpp)	

target_compile_features(test PRIVATE cxx_std_17)