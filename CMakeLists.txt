cmake_minimum_required(VERSION 3.10)
project(DataStructuresAndAlgorithms)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

# Create an executable for each .cpp file
foreach(source ${SOURCES})
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
endforeach()