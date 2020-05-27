cmake_minimum_required(VERSION 3.16)
project(splay)

set(CMAKE_CXX_STANDARD 14)

add_executable(splay
        main.cpp
        splay-tree/Tree.h
        #splay-tree/DataPiece.h
        #splay-tree/NodeData.h
        splay-tree/construct.cpp
        splay-tree/std_in_out.cpp
        splay-tree/splay.cpp
        splay-tree/utilitites.cpp
        splay-tree/find.cpp
        splay-tree/basic_operations.cpp
        splay-tree/operations.cpp
        )
add_executable(output output.cpp)
add_executable(sav sol.cpp)