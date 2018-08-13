cmake_minimum_required(VERSION 3.12)
project(ce4302_Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ce4302_Project1 main.cpp processor/cpu.cpp processor/cpu.h processor/cache.cpp processor/cache.h processor/control.cpp processor/control.h memory/mainMemory.cpp memory/mainMemory.h GUI/display.cpp GUI/display.h)