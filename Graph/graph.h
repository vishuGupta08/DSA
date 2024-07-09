#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adjList;
public:
    Graph(int v){ // parameterized constructor
        this -> v = v;
        adjList.resize(v);
    }
    // undirected unweighted graph
    void addEdge(int v, int w){
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void printGraph(){
        for(int i = 0; i< v; i++){
            cout<<"Adjency List of vertex " << i << ":\n";
            for(auto x: adjList[i]){
                cout<<x<<"->";
            }
            cout<<"\n";

        }
    }
    
    int getVertices(){
        return v;
    }

    vector<int> getAdjList(int v){
        return adjList[v];
    }
};    
#endif
