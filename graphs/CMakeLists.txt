cmake_minimum_required(VERSION 3.15)
project(graphs)

set(CMAKE_CXX_STANDARD 17)


add_executable(graphs main.cpp IGraph.h MatrixGraph.h ListGraph.h IGraph.cpp MatrixGraph.cpp ListGraph.cpp SetGraph.cpp SetGraph.h ArcGraph.cpp ArcGraph.h)