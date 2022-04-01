cmake_minimum_required(VERSION 3.16)
project(Clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(Clion main.cpp DFA.cpp DFA.h NFA.cpp NFA.h State.cpp State.h Parser.cpp Parser.h Transition.cpp Transition.h)
