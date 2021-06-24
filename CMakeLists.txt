cmake_minimum_required(VERSION 3.19)
project(proyecto_de_curso_team_triple_for)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Graph)
include_directories(Graph/Algorithms)
include_directories(Parser)

add_executable(proyecto_de_curso_team_triple_for
        Graph/Algorithms/astar.h
        Graph/Algorithms/bfs.h
        Graph/Algorithms/dfs.h
        Graph/Algorithms/dijkstra.h
        Graph/Algorithms/kruskal.h
        Graph/Algorithms/prim.h
        Graph/DirectedGraph.h
        Graph/graph.h
        Graph/UndirectedGraph.h
        Parser/Data/airports.json
        Parser/Data/desktop.ini
        Parser/Data/pe.json
        Parser/desktop.ini
        main.cpp)
