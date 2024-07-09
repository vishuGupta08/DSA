#include "graph.h"
#include <iostream>
#include <queue>
using namespace std;

void dfsRecUtil(int v, vector<bool> &visited, Graph &g)
{
    visited[v] = true;
    cout << v << " ";
    for (auto x : g.getAdjList(v))
    {
        if (!visited[x])
        {
            dfsRecUtil(x, visited, g);
        }
    }
}

void dfs(Graph &g, int v)
{
    cout << "DFS in Action \n";
    vector<bool> visited(g.getVertices(), false);
    dfsRecUtil(v, visited, g);
}

void bfs(Graph &g, int start)
{
    queue<int> q;
    vector<int> visited(g.getVertices(), false);
    visited[start]= true;
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        cout<<v<< " ";
        q.pop();
        for(auto x: g.getAdjList(v)){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main()
{
    Graph graph(7);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(0, 6);
    graph.addEdge(1, 4);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    graph.printGraph();

    // dfs(graph, 0);

    bfs(graph, 0);

    return 0;
}