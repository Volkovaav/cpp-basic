cmake_minimum_required(VERSION 3.5)

project(cont CXX)

add_executable(cont main.cpp)

target_compile_features(cont PUBLIC cxx_std_17)

if (MSVC)
    target_compile_options(cont PUBLIC /W4 /WX)
else()
    target_compile_options(cont PUBLIC -Wall -Wextra -pedantic -Werror)
endif()