# Data-Structures-and-Algorithm
This repository contains implementations of basic data structures and algorithms using C++.

## Build and Run Instructions

This project uses CMake for building. All build artifacts are kept in the `build/` directory to keep the source directory clean.

### Prerequisites
- CMake (version 3.10 or higher)
- MinGW-w64 (for g++ compiler on Windows)
- Bash shell (for running scripts)

### Building and Running a Specific Program
Use the provided `build_and_run.sh` script for easy compilation and execution:

```bash
./build_and_run.sh <program_name>
```

**Example:**
```bash
./build_and_run.sh Prog_1_Sorting_1_BubbleSort
```

This will:
- Configure the build (if needed)
- Compile the specified program
- Run the executable immediately

### Building All Programs
To build all programs at once:

```bash
mkdir -p build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
```

### Running a Built Program
After building, run any program from the build directory:

```bash
cd build
./Prog_1_Sorting_1_BubbleSort.exe
```

## Search Tips
To search any topic or keyword in the files in the current directory:  
Type (in your shell): `grep -nr "[Keyword_to_search]" .`

## Editor
Use Visual Studio Code.  
To open a file through Cmd terminal in VS Code: `code [filename].cpp`

