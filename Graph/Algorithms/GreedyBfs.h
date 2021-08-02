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

template <typename TV, typename TE> class CompareVertex {
public:
  bool operator()(Vertex<TV, TE> *first, Vertex<TV, TE> *second) {
    return first->data > second->data;
  }
};

template <typename TV, typename TE> class GreedyBfs {
  map<Vertex<TV, TE> *, bool> visited;
  priority_queue<Vertex<TV, TE> *, vector<Vertex<TV, TE> *>,
                 CompareVertex<TV, TE>>
      distancesQueue;
  Graph<TV, TE> *graph;

public:
  GreedyBfs(Graph<TV, TE> *graph) : graph(graph) {}

  vector<TV> apply(string start, string end) {
      if (graph->vertexes.find(start) == graph->vertexes.end()){
          cout << "asdd" << endl;
      }
    if (graph->vertexes.find(start) == graph->vertexes.end() ||
        graph->vertexes.find(end) == graph->vertexes.end()) {
      return {};
    }
    vector<TV> dataResult;

    Vertex<TV, TE> *startV = graph->vertexes[start];
    Vertex<TV, TE> *endV = graph->vertexes[end];

    distancesQueue.push(startV);
    visited[startV] = true;
    string s = start;

    while (!distancesQueue.empty()) {
      Vertex<TV, TE> *top = distancesQueue.top();
      dataResult.push_back(top->data);
      distancesQueue.pop();
      if (top == endV) {
          return dataResult;
      }
      for (Edge<TV, TE> *edge : top->edges) {
        auto it = visited.find(edge->vertexes[1]);
        if (it == visited.end()) {
          visited[edge->vertexes[1]] = true;
          distancesQueue.push(edge->vertexes[1]);
        }
      }
    }
    return {};
  }
};
