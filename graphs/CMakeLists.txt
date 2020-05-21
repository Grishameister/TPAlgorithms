cmake_minimum_required(VERSION 3.16)
project(graphs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(graphs
        ArcGraph.cpp
        ArcGraph.h
        CMakeLists.txt
        IGraph.cpp
        IGraph.h
        ListGraph.cpp
        ListGraph.h
        main.cpp
        MatrixGraph.cpp
        MatrixGraph.h
        SetGraph.cpp
        SetGraph.h)
