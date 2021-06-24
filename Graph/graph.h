#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
};

template<typename TV, typename TE>
class Graph{
public:
    int count_edge = 0;
    int count_vertex = 0;
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    virtual bool insertVertex(string id, TV vertex);
    virtual bool createEdge(string id1, string id2, TE w);
    virtual bool deleteVertex(string id);
    virtual bool deleteEdge(string start, string end);
    virtual TE &operator()(string start, string end);
    virtual float density();
    virtual bool isDense(float threshold = 0.5);
    virtual bool isConnected();
    virtual bool isStronglyConnected() throw();
    bool empty(){
        return vertexes.empty();
    }
    void clear() {
        vertexes.clear();
    }

    virtual void displayVertex(string id);
    virtual bool findById(string id);
    virtual void display();
};

#endif