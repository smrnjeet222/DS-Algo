#include <cstring>
#include <iostream>
#include <list>
#include <map>

using namespace std;

template <typename T>
class Graph {
   private:
    map<T, list<T>> adjList;

   public:
    Graph() {
    }
    void AddEdge(T from, T to, bool bidir = true) {
        adjList[from].push_back(to);
        if (bidir) {
            adjList[to].push_back(from);
        }
    }
    void print() {
        for (auto row : adjList) {
            T key = row.first;
            cout << key << "->";
            for (T elem : row.second) {
                cout << elem << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph<string> g;

    g.AddEdge("Amritsar", "Delhi");
    g.AddEdge("Amritsar", "Jaipur");
    g.AddEdge("Delhi", "Siachen");
    g.AddEdge("Delhi", "Lucknow");
    g.AddEdge("Delhi", "Agra");
    g.AddEdge("Delhi", "Banglore");
    g.AddEdge("Amritsar", "Siachen");

    g.print();

    return 0;
}