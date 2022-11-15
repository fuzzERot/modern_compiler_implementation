cmake_minimum_required(VERSION 3.13)  # CMake version check
project(chap1)               
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard
set(CMAKE_CXX_FLAGS_DEBUG  "-g")      # debug mode

# Add main.cpp file of project root directory as source file
set(SOURCES main.cpp prog1.cpp slp.cpp util.cpp program.cpp)
set(HEADERS prog1.hpp slp.hpp util.hpp program.hpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(chap1 ${HEADERS} ${SOURCES})