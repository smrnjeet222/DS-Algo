#include <bits/stdc++.h>

#include <list>
using namespace std;

//Adjacency List
class Graph {
   private:
    int V;
    list<int>* adjList;

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
            cout << i << "->";
            for (int node : adjList[i]) {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void BFS(int src, int dest) {
        queue<int> q;
        bool* visited = new bool[V]{0};
        int* dist = new int[V]{0};
        int* parent = new int[V]{-1};

        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int node = q.front();
            cout << node << " ";
            q.pop();
            for (auto neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        cout << endl;
        // for (int i = 0; i < V; i++)
        // {
        //     cout<<"dist of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
        // }
        cout << "\nShortest Distance is " << dist[dest];
        cout << "\nShortest Path is : ";
        int temp = dest;
        while (temp != -1) {
            cout << temp << "<--";
            temp = parent[temp];
        }
    }
};

int main() {
    Graph g(6);

    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(0, 4);
    g.AddEdge(2, 4);
    g.AddEdge(2, 3);
    g.AddEdge(3, 5);
    g.AddEdge(3, 4);

    g.BFS(0, 5);
    cout << endl;
    g.print();

    return 0;
}