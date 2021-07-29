cmake_minimum_required(VERSION 3.13)
include(FetchContent)
project(proyecto_de_curso_team_triple_for)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(.)
include_directories(Graph)
include_directories(Graph/Algorithms)
include_directories(Parser)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


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
        Parser/parser.h
        Parser/parser.cpp
        Dset/ds.h
        Dset/dsarray.h
        main.cpp)


target_link_libraries(proyecto_de_curso_team_triple_for PRIVATE nlohmann_json::nlohmann_json stdc++fs)
