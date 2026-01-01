#!/bin/bash

# Script to build and run a specific C++ program
# Usage: ./build_and_run.sh <program_name>
# Example: ./build_and_run.sh Prog_1_Sorting_1_BubbleSort

if [ $# -eq 0 ]; then
    echo "Usage: $0 <program_name>"
    echo "Example: $0 Prog_1_Sorting_1_BubbleSort"
    exit 1
fi

PROGRAM=$1
BUILD_DIR="build"

# Create build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Change to build directory
cd $BUILD_DIR

# Configure with CMake if not already done or if CMakeLists.txt changed
if [ ! -f CMakeCache.txt ] || [ ../CMakeLists.txt -nt CMakeCache.txt ]; then
    echo "Configuring build..."
    cmake -G "MinGW Makefiles" ..
fi

# Build the specific program
echo "Building $PROGRAM..."
mingw32-make $PROGRAM

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Running $PROGRAM..."
    ./$PROGRAM.exe
else
    echo "Build failed for $PROGRAM"
    exit 1
fi