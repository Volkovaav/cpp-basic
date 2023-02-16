cmake_minimum_required(VERSION 3.8)

project(xo CXX)

add_executable(xo main.cpp)	

target_compile_features(xo PRIVATE cxx_std_17)