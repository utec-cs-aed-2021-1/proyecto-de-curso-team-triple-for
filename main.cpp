#include <filesystem>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Algorithms/FloydWarshall.h"
#include "Algorithms/GreedyBfs.h"
#include "Algorithms/astar.h"
#include "Algorithms/bfs.h"
#include "Algorithms/dfs.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/kruskal.h"
#include "Algorithms/prim.h"
#include "Graph/DirectedGraph.h"
#include "Graph/UndirectedGraph.h"
#include "Parser/parser.h"
#include "Algorithms/bellmanFord.h"
#include "iomanip"

using namespace std;

void directed();
void undirected();
void menu() {
  int op;
  do {
    cout << "=============================================" << endl;
    cout << "\t\t\tGraph data structure" << std::endl;
    cout << "=============================================" << endl;
    cout << "\t1 Directed graph" << std::endl;
    cout << "\t2 Undirected graph" << std::endl;
    cout << "\t3 Exit" << std::endl;
    cout << "Please select an option: ";
    cin >> op;
    switch (op) {
    case 1:
      directed();
      break;
    case 2:
      undirected();
      break;
    case 3:
      cout << "Exited the program" << endl;
      return;
    default:
      cout << "Entered an incorrect option" << endl;
    }
  } while (op == 1 || op == 2);
}

void directed() {
  int op = 0, w;
  bool pass;
  string key, key2;
  cout << "\tEnter the number of vertex: ";
  cin >> op;
  DirectedGraph<string, int> g;
  for (int i = 0; i < op; ++i) {
    do {
      cout << "\tEnter the name of vertex: ";
      cin >> key;
      if (!g.insertVertex(key, key)) {
        cout << "\tNames cannot be repeated" << endl;
        pass = true;
      } else
        pass = false;
    } while (pass);
  }
  do {
    cout << "\t1 Add a vertex" << std::endl;
    cout << "\t2 Delete a vertex" << std::endl;
    cout << "\t3 Add an edge" << std::endl;
    cout << "\t4 Delete an edge" << std::endl;
    cout << "\t5 Get density" << std::endl;
    cout << "\t6 Check if it is a connected graph" << std::endl;
    cout << "\t7 Check if it is a strongly connected graph" << std::endl;
    cout << "\t8 Check if it is a empty graph" << std::endl;
    cout << "\t9 Clear a graph" << std::endl;
    cout << "\t10 Display" << std::endl;
    cout << "\t11 Show dfs" << std::endl;
    cout << "\t12 Show bfs" << std::endl;
    cout << "\t13 Return to the previous menu" << std::endl;
    cout << "Please select an option: ";
    cin >> op;
    switch (op) {
    case 1: {
      cout << endl;
      cout << "\t\t Add a vertex" << endl;
      do {
        cout << "\tEnter the name of vertex: ";
        cin >> key;
        if (!g.insertVertex(key, key)) {
          cout << "\tNames cannot be repeated" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 2: {
      cout << endl;
      cout << "\t\t Delete a vertex" << endl;
      do {
        cout << "\tEnter the name of vertex: ";
        cin >> key;
        if (!g.deleteVertex(key)) {
          cout << "\tNames must exist" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 3: {
      cout << endl;
      cout << "\t\t Add an edge" << endl;
      do {
        cout << "\tEnter the name of first vertex: ";
        cin >> key;
        cout << "\tEnter the name of second vertex: ";
        cin >> key2;
        cout << "\tEnter the weight for the edge: ";
        cin >> w;
        if (!g.createEdge(key, key2, w)) {
          cout << "\tNames must exist" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 4: {
      cout << endl;
      cout << "\t\t Delete an edge" << endl;
      do {
        cout << "\tEnter the name of first vertex: ";
        cin >> key;
        cout << "\tEnter the name of second vertex: ";
        cin >> key2;
        if (!g.deleteEdge(key, key2)) {
          cout << "\tNames must exist" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 5: {
      cout << endl;
      cout << "\t\t Get density" << endl;
      cout << "Density: " << g.density() << endl;
      cout << endl;
      break;
    }
    case 6: {
      cout << endl;
      cout << "\t\t Check if it is a connected graph" << endl;
      if (g.isConnected())
        cout << "The graph is connected" << endl;
      else
        cout << "The graph is not connected" << endl;
      cout << endl;
      break;
    }
    case 7: {
      cout << endl;
      cout << "\t\t Check if it is a strongly connected graph" << endl;
      if (g.isStronglyConnected())
        cout << "The graph is strongly connected" << endl;
      else
        cout << "The graph is not strongly connected" << endl;
      cout << endl;
      break;
    }
    case 8: {
      cout << endl;
      cout << "\t\t Check if it is a strongly connected graph" << endl;
      if (g.empty())
        cout << "The graph is empty" << endl;
      else
        cout << "The graph is not empty" << endl;
      cout << endl;
      break;
    }
    case 9: {
      cout << endl;
      cout << "\t\t Clear a graph" << endl;
      g.clear();
      cout << "The graph is clear" << endl;
      cout << endl;
      break;
    }
    case 10: {
      cout << endl;
      g.display();
      cout << endl;
      break;
    }
    case 11: {
      cout << endl;
      cout << "\tEnter the name of the starting vertex: ";
      cin >> key;
      Dfs<string, int> dfs(&g, key);
      vector<Vertex<string, int> *> result = dfs.apply();
      cout << "\t";
      for (auto vertex : result) {
        cout << vertex->data << " ";
      }
      cout << endl;
      cout << endl;
      break;
    }
    case 12: {
      cout << endl;
      cout << "\tEnter the name of the starting vertex: ";
      cin >> key;
      Bfs<string, int> bfs(&g, key);
      vector<Vertex<string, int> *> result = bfs.apply();
      cout << "\t";
      for (auto vertex : result) {
        cout << vertex->data << " ";
      }
      cout << endl;
      cout << endl;
      break;
    }
    case 13:
      return;
    default:
      cout << "Entered an incorrect option" << endl;
    }
  } while (op != 13);
}
void undirected() {
  int op = 0, w;
  bool pass;
  string key, key2;
  cout << "\tEnter the number of vertex: ";
  cin >> op;
  UnDirectedGraph<string, int> g;
  for (int i = 0; i < op; ++i) {
    do {
      cout << "\tEnter the name of vertex: ";
      cin >> key;
      if (!g.insertVertex(key, key)) {
        cout << "\tNames cannot be repeated" << endl;
        pass = true;
      } else
        pass = false;
    } while (pass);
  }
  do {
    cout << "\t1 Add a vertex" << std::endl;
    cout << "\t2 Delete a vertex" << std::endl;
    cout << "\t3 Add an edge" << std::endl;
    cout << "\t4 Delete an edge" << std::endl;
    cout << "\t5 Get density" << std::endl;
    cout << "\t6 Check if it is a connected graph" << std::endl;
    cout << "\t7 Check if it is a empty graph" << std::endl;
    cout << "\t8 Clear a graph" << std::endl;
    cout << "\t9 Display" << std::endl;
    cout << "\t10 Show kruskal" << std::endl;
    cout << "\t11 Show prim" << std::endl;
    cout << "\t12 Show dfs" << std::endl;
    cout << "\t13 Show bfs" << std::endl;
    cout << "\t14 Return to the previous menu" << std::endl;
    cout << "Please select an option: ";
    cin >> op;
    switch (op) {
    case 1: {
      cout << endl;
      cout << "\t\t Add a vertex" << endl;
      do {
        cout << "\tEnter the name of vertex: ";
        cin >> key;
        if (!g.insertVertex(key, key)) {
          cout << "\tNames cannot be repeated" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 2: {
      cout << endl;
      cout << "\t\t Delete a vertex" << endl;
      do {
        cout << "\tEnter the name of vertex: ";
        cin >> key;
        if (!g.deleteVertex(key)) {
          cout << "\tNames must exist" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 3: {
      cout << endl;
      cout << "\t\t Add an edge" << endl;
      do {
        cout << "\tEnter the name of first vertex: ";
        cin >> key;
        cout << "\tEnter the name of second vertex: ";
        cin >> key2;
        cout << "\tEnter the weight for the edge: ";
        cin >> w;
        if (!g.createEdge(key, key2, w)) {
          cout << "\tNames must exist" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 4: {
      cout << endl;
      cout << "\t\t Delete an edge" << endl;
      do {
        cout << "\tEnter the name of vertex: ";
        cin >> key;
        cout << "\tEnter the name of vertex: ";
        cin >> key2;
        if (!g.deleteEdge(key, key2)) {
          cout << "\tNames must exist" << endl;
          pass = true;
        } else
          pass = false;
      } while (pass);
      cout << endl;
      break;
    }
    case 5: {
      cout << endl;
      cout << "\t\t Get density" << endl;
      cout << "Density: " << g.density() << endl;
      cout << endl;
      break;
    }
    case 6: {
      cout << endl;
      cout << "\t\t Check if it is a connected graph" << endl;
      if (g.isConnected())
        cout << "The graph is connected" << endl;
      else
        cout << "The graph is not connected" << endl;
      cout << endl;
      break;
    }
    case 7: {
      cout << endl;
      cout << "\t\t Check if it is a strongly connected graph" << endl;
      if (g.empty())
        cout << "The graph is empty" << endl;
      else
        cout << "The graph is not empty" << endl;
      cout << endl;
      break;
    }
    case 8: {
      cout << endl;
      cout << "\t\t Clear a graph" << endl;
      g.clear();
      cout << "The graph is clear" << endl;
      cout << endl;
      break;
    }
    case 9: {
      cout << endl;
      g.display();
      cout << endl;
      break;
    }
    case 10: {
      cout << endl;
      Kruskal<string, int> kruskal(&g);
      UnDirectedGraph<string, int> result = kruskal.apply();
      result.display();
      cout << endl;
      break;
    }
    case 11: {
      cout << endl;
      cout << "\tEnter the name of the starting vertex: ";
      cin >> key;
      Prim<string, int> prim(&g, key);
      UnDirectedGraph<string, int> result = prim.apply();
      result.display();
      cout << endl;
      break;
    }
    case 12: {
      cout << endl;
      cout << "\tEnter the name of the starting vertex: ";
      cin >> key;
      Dfs<string, int> dfs(&g, key);
      vector<Vertex<string, int> *> result = dfs.apply();
      cout << "\t";
      for (auto vertex : result) {
        cout << vertex->data << " ";
      }
      cout << endl;
      break;
    }
    case 13: {
      cout << endl;
      cout << "\tEnter the name of the starting vertex: ";
      cin >> key;
      Bfs<string, int> bfs(&g, key);
      vector<Vertex<string, int> *> result = bfs.apply();
      cout << "\t";
      for (auto vertex : result) {
        cout << vertex->data << " ";
      }
      cout << endl;
      cout << endl;
      break;
    }
    case 14:
      return;
    default:
      cout << "Entered an incorrect option" << endl;
    }
  } while (op != 14);
}
void test() {
  std::cout << "================================================" << std::endl;
  std::cout << "MENU UNDIRECT GRAPH TESTER" << std::endl;
  std::cout << "================================================" << std::endl;

  DirectedGraph<char, int> dg;

  dg.insertVertex("S", 'S');
  dg.insertVertex("A", 'A');
  dg.insertVertex("B", 'B');
  dg.insertVertex("C", 'C');
  dg.insertVertex("D", 'D');
  dg.insertVertex("E", 'E');

  dg.createEdge("S", "E", 8);
  dg.createEdge("S", "A", 10);
  dg.createEdge("B", "A", 1);
  dg.createEdge("A", "C", 2);
  dg.createEdge("C", "B", -2);
  dg.createEdge("D", "C", -1);
  dg.createEdge("D", "A", -4);
  dg.createEdge("E", "D", 1);

  bellmanFord<char, int> bellmanford = bellmanFord(&dg, "S");

  pair<unordered_map<string, int>, unordered_map<string, string>> result = bellmanford.apply();
  cout << "Distancias: \n";
  for (auto& key: result.first) {
      cout << key.first << ": " << key.second << std::endl;
  }
  cout << "Padres: \n";
  for (auto& key: result.second) {
      cout << key.first << ": " << key.second << std::endl;
  }

  // FloydWarshall<char, int> floydWarhsall = FloydWarshall(&dg);
  //
  // pair<vector<vector<int>>, vector<vector<string>>> result =
  //     floydWarhsall.apply();
  // floydWarhsall.display();
}

int main(int argc, char *argv[]) {
  // do not modify this
  filesystem::current_path("../Parser/Data");
  //
  // menu();
   test();
  // auto jsonResult = getJsonFromFile("airports.json");
  // auto graph = getGraph(jsonResult);
  // GreedyBfs<string, double> greedyBfs = GreedyBfs(&graph);
  // auto x = greedyBfs.apply("7252", "5502");
  // for (auto m : x) {
  //     auto x = getairportfromid(m,jsonResult);
  //     x.display();
  //     cout << endl;
  // }
  //
  auto jsonResult = getJsonFromFile("airports.json");
  auto graph = getGraph(jsonResult);
  string origin = "341";
  string destiny = "3199";
  // auto heuristic = getHeuristic(destiny, jsonResult);
  // AStar<string, double> astar = AStar(&graph, heuristic);
  // auto x = astar.apply(origin, destiny);
  // for (auto m : x) {
  //   auto x = getairportfromid(m, jsonResult);
  //   x.display();
  //   cout << endl;
  // }
  //
  // cout << endl << endl;
  /*GreedyBfs<string, double> greedyBfs = GreedyBfs(&graph);
  auto z = greedyBfs.apply(origin, destiny);

  for (auto m : z) {
      auto x = getairportfromid(m,jsonResult);
      x.display();
      cout << endl;
  }*/

  /*
  auto jsonResult = getJsonFromFile("airports.json");
  // auto heuristic = getHeuristic("2792",jsonResult);
  auto graph = getGraph(jsonResult);
  cout << graph.count_edge << endl;
  cout << graph.count_vertex << endl;
  // graph.display();
  // auto x = getairportfromid("2802",jsonResult);
  // x.display();*/
  return EXIT_SUCCESS;
}
