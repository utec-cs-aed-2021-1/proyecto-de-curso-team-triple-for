# Algoritmos y Estructura de Datos
## Proyecto sobre Grafos
--------

## Integrantes
- Jorge Collazos
- Luis Berrospi
- Mario Ríos

----

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. La estructura debe soportar los métodos y algoritmos descritos a continuacion:  

## JSON Paser

Nlohmann json library was used. 
Harversine formula was used to get the distance from two points given its latitude and longitude.

#### Airport

Struct to map data from JSON

#### Methods

* getJsonFromFile
    * Input: filename string
    * Output: JSON array object from given file
* getHeuristic
    * Input: airportId, target json
    * Output: unordered_map containing heuristic from the given airportId
* getGraph
    * Input: json target
    * Output: undirected graph containing airports
* getairportfromid
    * Input: airportid and json target
    * Output: Airport struct
* distance
    * Input: two points on the earth
    * Output: distance in km using Harversine formula

## Graph

Abstract interface to determine the members and functions of specific implementations (undirected and directed)

### Members

* Vertex
    * data
    * edges
     
* Edge
    * weight
    * vertexes

#### Methods

* vertexes
    * unordered_map containing the relation between alias string and the vertex
* insertVertex
* createEdge
* deleteVertex
* deleteEdge
* density
* isDense
* isConnected
* isStronglyConnected
* empty
* clear
* displayVertex
* findById
* display
* findDifferent
    * find adjacent node from a node and an edge
* findEdge
* findVertex

## Greedy BFS

#### EntryBFS

* cost
* vertex
    * vertex holding entry 
* parent;
    * parent holding

#### Comparator

* operator
    * compare two EntryBFS by its cost property

#### Members

* visited
* distancesQueue
    * priority queue containing distances and using custom comparator
* graph

#### Methods

* findEntryFromVertex
    * Input: vertex, vector of entryBFS
    * Output: entryBFS that contains input vertex
* GreedyBfs
    * Input: graph
    * Output: none
* apply
    * Input: start and end strings
    * Output: finds minimum path from start to end and returns the vector of node's ids using parents and distances queue


## A*

#### EntryList

* vertex
    * vertex holding entry 
* parent;
    * parent holding
* g
    * distance cost
* h
    * heuristic cost

#### Comparator

* cmpEntryList
    * compares two entryList by its g (distance) and h (heuristic) properties

#### Members

* graph
* heuristic
* openList
* closedList

#### Methods

* findEntryFromVertex
    * Input: vertex, vector of entryList
    * Output: entryList that contains input vertex
* AStar
    * Input: graph, heuristic
    * Output: none
* apply
    * Input: start string, end string and heuristic unordered_map
    * Output: finds minimum path from start to end 

## DFS


#### Members

* graph
* start_id

#### Methods

* Dfs
    * Input: graph and start id
    * Output: none
* apply
    * Input: none
    * Output: list of vertexes traversed using Dfs method

## BFS

* graph
* start_id

#### Methods

* Dfs
    * Input: connected graph and start id
    * Output: none
* apply
    * Input: none
    * Output: list of vertexes traversed using Bfs method

