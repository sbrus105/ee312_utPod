cmake_minimum_required(VERSION 3.14)
project(ee312_utPod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ee312_utPod
        song.h
        utPod.h
        utPodDriver.cpp
        song.cpp)
