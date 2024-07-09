#include"graph.h"
#include <iostream>
using namespace std;

int main(){
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,3);
    graph.addEdge(0,6);
    graph.addEdge(1,4);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    graph.printGraph();


    return 0;
}