cmake_minimum_required(VERSION 3.15)

project(game CXX)

add_executable(game main.cpp game.cpp score.cpp game.h high_score.h)
target_compile_features(game PUBLIC cxx_std_17)
