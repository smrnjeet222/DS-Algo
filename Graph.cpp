#include <bits/stdc++.h>
#include <list>
using namespace std;

//Adjacency List
class Graph {
private:
    int V;
    list<int> *adjList;

public:
    Graph(int v) {
        V = v;
        adjList = new list<int>[v];
    }

    void AddEdge(int from, int to, bool bidir = true) {
        adjList[from].push_back(to);
        if (bidir) {
            adjList[to].push_back(from);
        }
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout<< i <<"->";
            for(int node:adjList[i]){
                cout<< node<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g(4);

    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(0,3);
    g.AddEdge(1,3);
    g.AddEdge(3,2);
    
    g.print();

    return 0;
}