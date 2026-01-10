#!/bin/bash

# Script to build and run a specific C++ program
# Usage: ./build_and_run.sh <filename>.cpp
# Example: ./build_and_run.sh Prog_1_Sorting_1_BubbleSort.cpp

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename>.cpp"
    echo "Example: $0 Prog_1_Sorting_1_BubbleSort.cpp"
    exit 1
fi

CPP_FILE=$1
BUILD_DIR="build"

# Check if the file exists
if [ ! -f "$CPP_FILE" ]; then
    echo "Error: File $CPP_FILE not found."
    exit 1
fi

# Extract basename without extension
BASENAME=$(basename "$CPP_FILE" .cpp)

# Create build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Change to build directory
cd $BUILD_DIR

# Build the program using g++
echo "Building $CPP_FILE..."
g++ -g "../$CPP_FILE" -o "$BASENAME.exe"

# Check if build was successful
if [ $? -eq 0 ]; then
    echo "Running $BASENAME.exe..."
    ./$BASENAME.exe
else
    echo "Build failed for $CPP_FILE"
    exit 1
fi