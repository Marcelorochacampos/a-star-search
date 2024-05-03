cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_CXX_STANDARD 14)

project(a_star_search)
add_executable(a_star_search_executable
    src/main.cpp
    src/board_mapper.cpp
    src/board_mapper.h
    src/draw.cpp
    src/draw.h
    src/node.cpp
    src/node.h
    src/nodes.hpp
    src/parser.cpp
    src/parser.h
    src/pathfind.cpp
    src/pathfind.h
    src/state.hpp
)

configure_file(src/maze.board ${CMAKE_CURRENT_BINARY_DIR}/maze.board COPYONLY)