cmake_minimum_required(VERSION 3.8)
project(graph)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SpareGraph.cpp SpareGraph.h DenseGraph.cpp DenseGraph.h ReadGraph.cpp ReadGraph.h Component.cpp Component.h Path.cpp Path.h ShortestPath.cpp ShortestPath.h)
add_executable(graph ${SOURCE_FILES})