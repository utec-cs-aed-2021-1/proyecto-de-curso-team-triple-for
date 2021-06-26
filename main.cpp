#include <iostream>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"

using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "================================================" << std::endl;
    std::cout << "MENU UNDIRECT GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;
    
    //Tester::executeExamples();
    //Tester::executeParser();

    auto* g = new UnDirectedGraph<int, int>();
    g->insertVertex("a", 1);
    g->insertVertex("b", 2);
    g->insertVertex("c", 3);
    g->insertVertex("d", 4);

    g->createEdge("a", "b", 2);
    g->createEdge("a", "d", 5);

    g->display();

    //g->deleteVertex("a");
    g->deleteEdge("a", "b");

    std::cout << std::endl;
    std::cout << std::endl;

    g->display();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "MENU DIRECT GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    //Tester::executeExamples();
    //Tester::executeParser();

    auto* d = new DirectedGraph<int, int>();
    d->insertVertex("a", 1);
    d->insertVertex("b", 2);
    d->insertVertex("c", 3);

    d->createEdge("a", "b", 2);
    d->createEdge("b", "a", 6);

    d->display();

    //g->deleteVertex("a");

    d->deleteEdge("b", "a");
    std::cout << std::endl;
    std::cout << std::endl;

    d->display();
    return EXIT_SUCCESS;
}