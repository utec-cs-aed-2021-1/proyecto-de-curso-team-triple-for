#pragma once

#include "graph.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template <typename TV, typename TE> struct entryBfs {
  TE cost;
  Vertex<TV, TE> *vertex;
  entryBfs(Vertex<TV, TE> *vertex_) : vertex(vertex_), cost(0) {}
};

template <typename TV, typename TE> class CompareVertex {
public:
  bool operator()(entryBfs<TV, TE> *first, entryBfs<TV, TE> *second) {
    return first->cost > second->cost;
  }
};

template <typename TV, typename TE> class GreedyBfs {
  map<Vertex<TV, TE> *, bool> visited;
  priority_queue<entryBfs<TV, TE> *, vector<entryBfs<TV, TE> *>,
                 CompareVertex<TV, TE>>
      distancesQueue;
  Graph<TV, TE> *graph;

public:
  GreedyBfs(Graph<TV, TE> *graph) : graph(graph) {}

  vector<TV> apply(string start, string end) {
    if (graph->vertexes.find(start) == graph->vertexes.end() ||
        graph->vertexes.find(end) == graph->vertexes.end()) {
      return {};
    }
    vector<TV> dataResult;

    Vertex<TV, TE> *startV = graph->vertexes[start];
    Vertex<TV, TE> *endV = graph->vertexes[end];

    distancesQueue.push(new entryBfs<TV, TE>(startV));
    visited[startV] = true;
    string s = start;

    while (!distancesQueue.empty()) {
      entryBfs<TV,TE> *top = distancesQueue.top();
      dataResult.push_back(top->vertex->data);
      distancesQueue.pop();
      if (top->vertex == endV) {
        return dataResult;
      }
      for (Edge<TV, TE> *edge : top->vertex->edges) {
        auto it = visited.find(edge->vertexes[1]);
        if (it == visited.end()) {
          visited[edge->vertexes[1]] = true;
          entryBfs<TV,TE>* target = new entryBfs<TV,TE>(edge->vertexes[1]);
          target->cost = edge->weight;
          distancesQueue.push(target);
        }
      }
    }
    return {};
  }
};
