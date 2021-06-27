#include "Graph/UndirectedGraph.h"
#include <climits>
template<typename TV, typename TE>
class Prim{
public:
    UnDirectedGraph<TV, TE> graph;
    string start_id;
    Prim(UnDirectedGraph<TV, TE> *graph, string id) {
        this->graph = *graph;
        start_id = id;
    }

    UnDirectedGraph<TV, TE> apply(){
        //std::unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*>  parents;
        char id = 'a'; /* max graph 255 nodes :c*/
        auto* result = new  UnDirectedGraph<TV, TE>();
        std::unordered_map<Vertex<TV, TE>*, string> ids;
        std::unordered_map<Vertex<TV, TE>*, int> dist;
        std::unordered_map<Vertex<TV, TE>*, Vertex<TV, TE>*> parent;

        for (auto &vertex : graph.vertexes) {
            dist[vertex.second] = INT_MAX;
            parent[vertex.second] = nullptr;
            ids[vertex.second] = id;
            id++;
        }

        Vertex<TV, TE>* vAdr = graph.vertexes[start_id];
        /* first is always 0 */
        dist[vAdr] = 0;
        /* add 0 to the solution */
        //ids[vAdr] = id;
        //id++;
        result->insertVertex(ids[vAdr], vAdr->data);

        while (!dist.empty()) {

            int min = INT_MAX;
            Vertex<TV, TE>* min_vertex;
            for (auto &k : dist) {
                if (k.second < min) {
                    min = k.second;
                    min_vertex = k.first;
                }
            }


            result->insertVertex(ids[min_vertex], min_vertex->data);
            if (parent[min_vertex] != nullptr) {
                result->createEdge(ids[min_vertex], ids[parent[min_vertex]], dist[min_vertex]);
            }

            dist.erase(min_vertex);

            for (auto& edge: min_vertex->edges) {
                Vertex<TV, TE>* adj_vertex = edge->vertexes[0] != min_vertex ? edge->vertexes[0] : edge->vertexes[1];
                if (dist.find(adj_vertex) != dist.end()) {
                    if (dist[adj_vertex] > edge->weight) {
                        parent[adj_vertex] = min_vertex;
                        dist[adj_vertex] = edge->weight;
                    }
                }
            }
        }



        for (auto &k : dist) {
            cout << k.second << " ";
        }
        for (auto &k : parent) {
            cout << k.second << " ";
        }
        return *result;
    }

};