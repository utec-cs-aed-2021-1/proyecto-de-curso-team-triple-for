#include <iostream>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "UndirectedGraph.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;
    
    //Tester::executeExamples();
    //Tester::executeParser();

    auto* g = new UnDirectedGraph<int, int>();
    g->insertVertex("a", 1);
    g->insertVertex("b", 2);
    g->insertVertex("c", 3);

    g->createEdge("a", "b", 2);

    g->display();

    //g->deleteVertex("a");
    g->deleteEdge("a", "b");

    g->display();

    return EXIT_SUCCESS;
}