#include <bits/stdc++.h>
using namespace std;

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid[0].length();
    int m = grid.size();

    queue<int> q;

    vector<bool> visited(n * m, 0);
    vector<int> dist(n * m, 0);
    vector<int> parent(n * m, -1);
    vector<char> bo(n * m);
    for (int i = 0; i < m; i++) {
        string s = grid[i];
        for (int j = 0; j < n; j++) {
            bo[i * n + j] = char(s[j]);
        }
    }

    q.push(startX * n + startY);
    visited[startX * n + startY] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int move[] = {(node - 1), (node + 1), (node - n), (node + n)};

        for (int i = 0; i < 4; i++) {
            if (node % n == 0 && i == 0) continue;
            if ((node + 1) % n == 0 && i == 1) continue;
            if (node < n && i == 2) continue;
            if (node >= (m - 1) * n && i == 3)
                continue;

            else if (bo[move[i]] == '.') {
                if (!visited[move[i]]) {
                    q.push(move[i]);
                    visited[move[i]] = true;
                    dist[move[i]] = dist[node] + 1;
                    parent[move[i]] = node;
                }
            }
        }
    }
    int temp = goalX * n + goalY;
    vector<vector<int>> g(m, vector<int>(n, 0));

    while (temp != -1) {
        cout << temp << "<-";
        int x = temp % n;
        g[(temp - x) / n][x] = 1;
        temp = parent[temp];
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    return dist[goalX * n + goalY];
}

int main() {
    vector<string> v = { "...X..",
                         ".X....",
                         ".X..X.",
                         ".X.X.."};
    
    cout<<"MINPATH: "<< minimumMoves(v, 3,0, 3,5);

    return 0;
}