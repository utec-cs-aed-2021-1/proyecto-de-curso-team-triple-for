#include <iostream>

//#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "Graph/DirectedGraph.h"
#include "Graph/UndirectedGraph.h"
#include "Algorithms/prim.h"
#include "Algorithms/kruskal.h"
#include "Algorithms/dfs.h"
#include "Algorithms/bfs.h"
using namespace std;

void directed();
void undirected();
void menu(){
    int op;
    do {
        cout << "=============================================" << endl;
        cout << "\t\t\tGraph data structure" << std::endl;
        cout << "=============================================" << endl;
        cout << "\t1 Directed graph" << std::endl;
        cout << "\t2 Undirected graph" << std::endl;
        cout << "\t3 Exit" << std::endl;
        cout<<"Please select an option: ";cin>>op;
        switch (op) {
            case 1:
                directed();
                break;
            case 2:
                undirected();
                break;
            case 3:
                cout << "Exited the program"<<endl;
                return;
            default:
                cout << "Entered an incorrect option"<<endl;
        }
    } while (op == 1 || op == 2);
}

void directed(){
    int op = 0, w;
    bool pass;
    string key, key2;
    cout << "\tEnter the number of vertex: ";cin>>op;
    DirectedGraph<string, int> g;
    for (int i = 0; i < op; ++i) {
        do{
            cout << "\tEnter the name of vertex: ";cin>>key;
            if(!g.insertVertex(key, key)){
                cout << "\tNames cannot be repeated" << endl;
                pass = true;
            }
            else pass = false;
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
        cout << "\t11 Return to the previous menu" << std::endl;
        cout<<"Please select an option: ";cin>>op;
        switch (op) {
            case 1:{
                cout<<endl;
                cout << "\t\t Add a vertex" << endl;
                do{
                    cout << "\tEnter the name of vertex: ";cin>>key;
                    if(!g.insertVertex(key, key)){
                        cout << "\tNames cannot be repeated" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 2:{
                cout<<endl;
                cout << "\t\t Delete a vertex" << endl;
                do{
                    cout << "\tEnter the name of vertex: ";cin>>key;
                    if(!g.deleteVertex(key)){
                        cout << "\tNames must exist" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 3:{
                cout<<endl;
                cout << "\t\t Add an edge" << endl;
                do{
                    cout << "\tEnter the name of first vertex: ";cin>>key;
                    cout << "\tEnter the name of second vertex: ";cin>>key2;
                    cout << "\tEnter the weight for the edge: ";cin>>w;
                    if(!g.createEdge(key,key2, w)){
                        cout << "\tNames must exist" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 4:{
                cout<<endl;
                cout << "\t\t Delete an edge" << endl;
                do{
                    cout << "\tEnter the name of first vertex: ";cin>>key;
                    cout << "\tEnter the name of second vertex: ";cin>>key2;
                    if(!g.deleteEdge(key,key2)){
                        cout << "\tNames must exist" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 5:{
                cout<<endl;
                cout << "\t\t Get density" << endl;
                cout << "Density: " <<g.density() <<endl;
                cout<<endl;
                break;
            }
            case 6:{
                cout<<endl;
                cout << "\t\t Check if it is a connected graph" << endl;
                if(g.isConnected()) cout << "The graph is connected"<<endl;
                else cout << "The graph is not connected"<<endl;
                cout<<endl;
                break;
            }
            case 7:{
                cout<<endl;
                cout << "\t\t Check if it is a strongly connected graph" << endl;
                if(g.isStronglyConnected()) cout << "The graph is strongly connected"<<endl;
                else cout << "The graph is not strongly connected"<<endl;
                cout<<endl;
                break;
            }
            case 8:{
                cout<<endl;
                cout << "\t\t Check if it is a strongly connected graph" << endl;
                if(g.empty()) cout << "The graph is empty"<<endl;
                else cout << "The graph is not empty"<<endl;
                cout<<endl;
                break;
            }
            case 9:{
                cout<<endl;
                cout << "\t\t Clear a graph" << endl;
                g.clear();
                cout << "The graph is clear"<<endl;
                cout<<endl;
                break;
            }
            case 10:{
                cout<<endl;
                g.display();
                cout<<endl;
                break;
            }
            case 11:
                return;
            default:
                cout << "Entered an incorrect option"<<endl;
        }
    } while (op != 11);
}
void undirected(){
    int op = 0, w;
    bool pass;
    string key, key2;
    cout << "\tEnter the number of vertex: ";cin>>op;
    UnDirectedGraph<string, int> g;
    for (int i = 0; i < op; ++i) {
        do{
            cout << "\tEnter the name of vertex: ";cin>>key;
            if(!g.insertVertex(key, key)){
                cout << "\tNames cannot be repeated" << endl;
                pass = true;
            }
            else pass = false;
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
        cout << "\t10 Return to the previous menu" << std::endl;
        cout<<"Please select an option: ";cin>>op;
        switch (op) {
            case 1:{
                cout<<endl;
                cout << "\t\t Add a vertex" << endl;
                do{
                    cout << "\tEnter the name of vertex: ";cin>>key;
                    if(!g.insertVertex(key, key)){
                        cout << "\tNames cannot be repeated" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 2:{
                cout<<endl;
                cout << "\t\t Delete a vertex" << endl;
                do{
                    cout << "\tEnter the name of vertex: ";cin>>key;
                    if(!g.deleteVertex(key)){
                        cout << "\tNames must exist" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 3:{
                cout<<endl;
                cout << "\t\t Add an edge" << endl;
                do{
                    cout << "\tEnter the name of first vertex: ";cin>>key;
                    cout << "\tEnter the name of second vertex: ";cin>>key2;
                    cout << "\tEnter the weight for the edge: ";cin>>w;
                    if(!g.createEdge(key,key2, w)){
                        cout << "\tNames must exist" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 4:{
                cout<<endl;
                cout << "\t\t Delete an edge" << endl;
                do{
                    cout << "\tEnter the name of vertex: ";cin>>key;
                    cout << "\tEnter the name of vertex: ";cin>>key2;
                    if(!g.deleteEdge(key,key2)){
                        cout << "\tNames must exist" << endl;
                        pass = true;
                    }
                    else pass = false;
                } while (pass);
                cout<<endl;
                break;
            }
            case 5:{
                cout<<endl;
                cout << "\t\t Get density" << endl;
                cout << "Density: " <<g.density() <<endl;
                cout<<endl;
                break;
            }
            case 6:{
                cout<<endl;
                cout << "\t\t Check if it is a connected graph" << endl;
                if(g.isConnected()) cout << "The graph is connected"<<endl;
                else cout << "The graph is not connected"<<endl;
                cout<<endl;
                break;
            }
            case 7:{
                cout<<endl;
                cout << "\t\t Check if it is a strongly connected graph" << endl;
                if(g.empty()) cout << "The graph is empty"<<endl;
                else cout << "The graph is not empty"<<endl;
                cout<<endl;
                break;
            }
            case 8:{
                cout<<endl;
                cout << "\t\t Clear a graph" << endl;
                g.clear();
                cout << "The graph is clear"<<endl;
                cout<<endl;
                break;
            }
            case 9:{
                cout<<endl;
                g.display();
                cout<<endl;
                break;
            }
            case 10:
                return;
            default:
                cout << "Entered an incorrect option"<<endl;
        }
    } while (op != 10);
}
void test(){
    std::cout << "================================================" << std::endl;
    std::cout << "MENU UNDIRECT GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tester::executeExamples();
    // Tester::executeParser();
    //DirectedGraph<char, int> g;
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
    /* test unconected graph */
    g.createEdge("e", "f", 4);
    g.createEdge("a","e",29);

    DirectedGraph<char, int> g2;
    //auto *g = new UnDirectedGraph<char, int>();
    g2.insertVertex("a", 'A');
    g2.insertVertex("b", 'B');
    g2.insertVertex("c", 'C');
    g2.insertVertex("d", 'D');
    g2.createEdge("a", "b", 2);
    g2.createEdge("b", "c", 1);
    g2.createEdge("c", "d", 2);
    if(g2.isStronglyConnected()) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    DirectedGraph<char, int> g3;
    //auto *g = new UnDirectedGraph<char, int>();
    g3.insertVertex("a", 'A');
    g3.insertVertex("b", 'B');
    g3.insertVertex("c", 'C');
    g3.insertVertex("d", 'D');
    g3.insertVertex("e", 'E');
    g3.createEdge("a", "b", 2);
    g3.createEdge("b", "c", 1);
    g3.createEdge("c", "d", 2);
    g3.createEdge("d", "a", 2);
    g3.createEdge("c", "e", 2);
    g3.createEdge("e", "c", 2);
    if(g3.isStronglyConnected()) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    auto val = g3("e","c");
    cout<<val<<endl;
    // Kruskal<char, int> kruskal(&g);
    //g.createEdge("a", "c", 5);
    // UnDirectedGraph<char, int> result = kruskal.apply();

    // result.display();

    Bfs<char,int> test(&g,"a");
    auto vectortest = test.apply();

    cout << vectortest.size() << endl;
    //

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
}

int main(int argc, char *argv[]) {
  menu();
  test();
  return EXIT_SUCCESS;
}
