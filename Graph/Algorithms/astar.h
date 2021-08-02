#pragma once

#include "graph.h"
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename TV, typename TE> struct entryList {
  Vertex<TV, TE> *vertex;
  Vertex<TV, TE> *parent;
  // normal cost
  TE g;
  // heuristic
  TE h;
  entryList(Vertex<TV, TE> *vertex_) {
    this->g = 0;
    this->h = 0;
    this->vertex = vertex_;
    this->parent = nullptr;
  }
};

template <typename TV, typename TE> struct entryComparator {
  bool operator()(entryList<TV, TE> *first, entryList<TV, TE> *second) {
    return (first->g + first->h) > (second->g + second->h);
  }
};

template <typename TV, typename TE> class AStar {
  Graph<TV, TE> *graph;
  unordered_map<TV, TE> heuristic;
  priority_queue<entryList<TV, TE> *, vector<entryList<TV, TE> *>,
                 entryComparator<TV, TE>>
      openList;
  priority_queue<entryList<TV, TE> *, vector<entryList<TV, TE> *>,
                 entryComparator<TV, TE>>
      closedList;

public:
  AStar(Graph<TV, TE> *g, unordered_map<TV, TE> h) : graph(g), heuristic(h) {}
  void apply(string start, string end) {
    if (graph->vertexes.find(start) == graph->vertexes.end() ||
        graph->vertexes.find(end) == graph->vertexes.end()) {
      // return {};
      return;
    }
    vector<TV> dataResult;

    Vertex<TV, TE> *startV = graph->vertexes[start];
    Vertex<TV, TE> *endV = graph->vertexes[end];
    entryList<TV, TE> *entry = new entryList<TV, TE>(startV);
    entry->h = heuristic[startV->data];

    while (!openList.empty()) {
      entryList<TV, TE> *top = openList.top();

      openList.pop();
      for (Edge<TV, TE> *edge : top->vertex->edges) {
        entryList<TV, TE> *newVertexEntry =
            new entryList<TV, TE>(edge->vertexes[1]);
        newVertexEntry->parent = top;

        // verify
        if (newVertexEntry->vertex == endV) {
          return;
        }
        newVertexEntry->g =
            top->g + abs(top->vertex->data - newVertexEntry->vertex->data);
      }
    }
  }
};
