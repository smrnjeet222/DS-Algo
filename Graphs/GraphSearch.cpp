#include <bits/stdc++.h>
using namespace std;

void BFS(int G[][7], int start, int n) {
    int i = start, j;
    queue<int> Q;
    int visited[7] = {0};
    cout << i << " ";
    visited[i] = 1;
    Q.push(i);
    while (!Q.empty()) {
        i = Q.front();
        Q.pop();
        for (j = 1; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                Q.push(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n) {
    static int visited[7] = {0};
    int j;
    if (visited[start] == 0) {
        cout << start << " ";
        visited[start] = 1;
        for (j = 1; j < n; j++) {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main() {
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    BFS(G, 2, 7);
    cout << endl;
    DFS(G, 4, 7);

    return 0;
}