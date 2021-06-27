#include <iostream>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Graph/DirectedGraph.h"
#include "Graph/UndirectedGraph.h"
#include "Algorithms/prim.h"
#include "Algorithms/kruskal.h"
using namespace std;

int main(int argc, char *argv[]) {

  std::cout << "================================================" << std::endl;
  std::cout << "MENU UNDIRECT GRAPH TESTER" << std::endl;
  std::cout << "================================================" << std::endl;

  // Tester::executeExamples();
  // Tester::executeParser();
    UnDirectedGraph<char, int> g;
   //auto *g = new UnDirectedGraph<char, int>();
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
    /* test unconected graph */
    g.createEdge("e", "f", 4);

    Kruskal<char, int> kruskal(&g);
    //g.createEdge("a", "c", 5);
    UnDirectedGraph<char, int> result = kruskal.apply();

    result.display();
    //
  // g->display();
  //
  // g->deleteVertex("a");
  // // g->deleteEdge("a", "b");
  //
  // std::cout << std::endl;
  // std::cout << std::endl;
  //
  // g->display();
  //
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  /*
  std::cout << "================================================" << std::endl;
  std::cout << "MENU DIRECT GRAPH TESTER" << std::endl;
  std::cout << "================================================" << std::endl;

  auto *d = new DirectedGraph<int, int>();
  d->insertVertex("a", 1);
  d->insertVertex("b", 2);
  d->insertVertex("c", 3);

  d->createEdge("a", "b", 2);
  d->createEdge("b", "a", 6);

  d->display();

  d->deleteVertex("a");
  d->deleteEdge("b", "a");
  std::cout << std::endl;
  std::cout << std::endl;
  cout << d->density() << endl;
  cout << d->isDense() << endl;

  d->display();*/
  return EXIT_SUCCESS;
}
