#include <iostream>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Algorithms/bfs.h"
#include "Algorithms/dfs.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/kruskal.h"
#include "Algorithms/prim.h"
#include "Graph/DirectedGraph.h"
#include "Graph/UndirectedGraph.h"
#include "Parser/parser.h"
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

  // Here you can run your own code with exit option in the menu

  // Tester::executeExamples();
  // Tester::executeParser();
  // DirectedGraph<char, int> g;
  UnDirectedGraph<char, int> g;
  g.insertVertex("a", 'A');
  g.insertVertex("b", 'B');
  g.insertVertex("c", 'C');
  g.insertVertex("d", 'D');
  g.insertVertex("e", 'E');
  g.insertVertex("f", 'F');

  g.createEdge("a", "b", 2);
  g.createEdge("c", "d", 1);
  g.createEdge("c", "b", 2);
  g.createEdge("a", "d", 5);
  g.createEdge("a", "c", 10);
  g.createEdge("e", "f", 4);
  g.createEdge("a", "e", 29);

  Dijkstra<char, int> dijkstra(&g, "a");

  vector<tuple<string, int, string>> result = dijkstra.apply();
  cout << setw(5) << "ver" << setw(5) << "dist" << setw(5) << "par" << endl;
  for (auto &row : result) {
    cout << setw(5) << get<0>(row) << setw(5) << get<1>(row) << setw(5)
         << get<2>(row) << endl;
  }

  DirectedGraph<char, int> dg;
  dg.insertVertex("a", 'A');
  dg.insertVertex("b", 'B');
  dg.insertVertex("c", 'C');
  dg.insertVertex("d", 'D');
  dg.insertVertex("e", 'E');
  dg.insertVertex("f", 'F');

  dg.createEdge("a", "b", 2);
  dg.createEdge("c", "d", 1);
  dg.createEdge("c", "b", 2);
  dg.createEdge("a", "d", 5);
  dg.createEdge("a", "c", 10);
  dg.createEdge("e", "f", 4);
  dg.createEdge("a", "e", 29);

  Dijkstra<char, int> dijkstra_dg(&dg, "a");

  vector<tuple<string, int, string>> result_dg = dijkstra_dg.apply();
  cout << setw(5) << "ver" << setw(5) << "dist" << setw(5) << "par" << endl;
  for (auto &row : result_dg) {
    cout << setw(5) << get<0>(row) << setw(5) << get<1>(row) << setw(5)
         << get<2>(row) << endl;
  }
}

int main(int argc, char *argv[]) {
  // menu();
  // test();
  getJsonFromFile("pe.json");
  return EXIT_SUCCESS;
}
