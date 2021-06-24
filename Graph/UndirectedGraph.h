#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
    bool insertVertex(string id, TV vertex) override{
        for(auto map : this->vertexes) {
            if(map.first == id){
                return false;
            } else{
                Vertex<TV, TE> new_vertex = new Vertex<TV, TE>;
                new_vertex.data = vertex;
                this->vertexes.template insert({id, &new_vertex});
                this->count_vertex++;
                return true;
            }
        }
    }
    bool createEdge(string id1, string id2, TE w) override{
        if(this->vertexes.at(id1) && this->vertexes.at(id2)){
            Edge<TV, TE> new_edge = new Edge<TV, TE>;
            new_edge.weight = w;
            new_edge->vertexes[0] = &this->vertexes.at(id1);
            new_edge->vertexes[1] = &this->vertexes.at(id2);
            this->vertexes.at(id1)->edges.push_back(new_edge);
            Edge<TV, TE> new_edge2 = new Edge<TV, TE>;
            new_edge2.weight = w;
            new_edge2->vertexes[0] = &this->vertexes.at(id2);
            new_edge2->vertexes[1] = &this->vertexes.at(id1);
            this->vertexes.at(id2)->edges.push_back(new_edge2);
            this->count_edge++;
            return true;
        }
        else{
            return false;
        }
    }
    bool deleteVertex(string id) override{ ////////faltaaaa
        for(auto map : this->vertexes) {
            if(map.first != id){
                return false;
            } else{
                for (auto const& i : map.second->edges) {
                    if(i->vertexes[1] == &this->vertexes.at(id)){
                        map.second->edges.remove(i);
                        this->count_edge--;
                    }
                }
            }
        }
        this->vertexes.erase(id);
        this->count_vertex--;
        return true;
    }
    bool deleteEdge(string start, string end) override{
        int deleteedge = 0;
        for(auto map : this->vertexes) {
            if(map.first == start){
                for (auto const& i : map.second->edges) {
                    if(i->vertexes[1] == &this->vertexes.at(end)){
                        map.second->edges.remove(i);
                        deleteedge++;
                    }
                }
            }
            if (map.first == end) {
                for (auto const &i : map.second->edges) {
                    if (i->vertexes[1] == &this->vertexes.at(start)) {
                        map.second->edges.remove(i);
                        deleteedge++;
                        this->count_edge--;
                    }
                }
            }
        }
        if(deleteedge == 2) return true;
        return false;
    }

    TE &operator()(string start, string end) ;

    float density() override{
        return (this->count_edge) / (this->count_vertex (this->count_vertex - 1));
    }

    bool isDense(float threshold = 0.5) override{
        if((this->count_edge) / (this->count_vertex (this->count_vertex - 1)) < threshold) return true;
        return false;
    }

    bool isConnected() ;
    bool isStronglyConnected() throw();
    void displayVertex(string id) override{
        cout<<id<<"-"<<this->vertexes.at(id)->data<<endl;
    }
    bool findById(string id) override{
        return this->vertexes.at(id);
    }
    virtual void display() override{
        for(auto map : this->vertexes) {
            cout << "Id: " << map.first << " value: " << this->vertexes.at(map.first) << endl;
            cout << "Connections :" <<endl;
            for (auto const& i : map.second->edges) {
                cout << i->vertexes[0].data << " - " << i->vertexes[1].data << " w: " << i.data <<endl;
            }
        }
    }
};

#endif