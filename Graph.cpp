#include <bits/stdc++.h>
using namespace std;

//Adjacency List
void addEdge(vector<int> adj[], int from, int to) {
    adj[from].push_back(to);
    adj[to].push_back(from);
}

void printGraph(vector<int> adj[], int V) {
    for (int i = 0; i < V; i++) {
        cout << "\nAdjacency list of vertex :" << i << "\nstart";
        for (auto x : adj[i])
            cout << "->" << x;
        cout << endl;
    }
}

int main() {
    int V = 5;

    //Adjacency list
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, V);

    return 0;
}