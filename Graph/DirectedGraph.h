#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
public:

    DirectedGraph() = default;

    bool insertVertex(string id, TV vertex) override{
        auto* newVertex = new Vertex<TV, TE>;
        newVertex->data = vertex;
        if (this->vertexes.find(id) != this->vertexes.end()) {
            return false;
        } else {
            this->vertexes[id] = newVertex;
            this->count_vertex++;
            return true;
        }
    }
    bool createEdge(string id1, string id2, TE w) override{
        if(this->vertexes.find(id1) != this->vertexes.end() && this->vertexes.find(id2)  != this->vertexes.end()){
            auto* new_edge = new Edge<TV, TE>;
            new_edge->weight = w;
            new_edge->vertexes[0] = this->vertexes[id1];
            new_edge->vertexes[1] = this->vertexes[id2];

            this->vertexes[id1]->edges.push_front(new_edge);

            this->count_edge++;
            return true;
        }
        else{
            return false;
        }
    }
    bool deleteVertex(string id) override{ ////////faltaaaa
        if (this->vertexes.find(id) == this->vertexes.end()) {
            return false;
        } else {
            for (auto it: this->vertexes[id]->edges){

            }
            this->vertexes.erase(id);
            return true;
        }
        /*for(auto map : this->vertexes) {
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
        return true;*/
    }
    bool deleteEdge(string start, string end) override{
        if (this->vertexes.find(start) == this->vertexes.end() && this->vertexes.find(start) == this->vertexes.end()) {
            cout << "GA\n";
            return false;
        }

        for (auto edge: this->vertexes[start]->edges) {
            if (edge->vertexes[0] == this->vertexes[start] && edge->vertexes[1] == this->vertexes[end]){
                this->vertexes[start]->edges.remove(edge);
                this->vertexes[end]->edges.remove(edge);
                break;
            }
        }
        return true;
    }

    TE &operator()(string start, string end) {

    }

    float density() override{
        return (float)(this->count_edge)/(this->count_vertex * (this->count_vertex - 1));
    }

    bool isDense(float threshold = 0.5) override{
        if((float)(this->count_edge)/(this->count_vertex * (this->count_vertex - 1))< threshold) return true;
        return false;
    }

    bool isConnected() {

    }

    bool isStronglyConnected() throw(){

    }

    void displayVertex(string id) override{
        cout<<id<<"-"<<this->vertexes.at(id)->data<<endl;
    }
    bool findById(string id) override{
        return this->vertexes.at(id);
    }
    void display() override{
        cout << "DISPLAY: \n";
        for (auto& it: this->vertexes) {
            cout << "Id: " << it.first << " value: " << it.second->data << endl;
            cout << "Edges :" <<endl;
            for (auto const& i : it.second->edges) {
                cout << "   {"<<i->vertexes[0]->data << ", " << i->vertexes[1]->data << "} w: " << i->weight <<endl;
            }
            std::cout << std::endl;
        }
    }
};

#endif