# Algoritmos y Estructura de Datos
## Proyecto sobre Grafos
--------

## Integrantes
- Jorge Collazos
- Luis Berrospi
- Mario Ríos

----

El proyecto del curso consiste en implementar una estructura de datos de grafo y un file parser. La estructura debe soportar los métodos y algoritmos descritos a continuacion:  


## Clases

### Greedy BFS

#### EntryBFS

* TE cost
    * cost of EntryBFS 
* Vertex<TV,TE> *vertex
    * vertex holding entry 

#### Comparator

* bool operator()
    * compare two EntryBFS by its cost property

#### Members

* map<Vertex<TV, TE> *, bool> visited;
* priority_queue<entryBfs<TV, TE> *, vector<entryBfs<TV, TE> *>,CompareVertex<TV, TE>> distancesQueue;
* Graph<TV, TE> *graph;

#### Methods

* GreedyBfs(Graph<TV,TE> *graph)
* vector<TV> apply(string start, string end)
    * finds minimum path from start to end and returns the vector of node's ids

