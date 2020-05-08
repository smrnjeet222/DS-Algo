#include <stdio.h>

#include <iostream>

using namespace std;

#define N 8

int isSafe(int x, int y, int grid[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == -1);
}

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %2d ", grid[i][j]);
        }
        cout << endl;
    }
}

int solveUtil(int x, int y, int imove, int grid[N][N], int xm[N], int ym[N]) {
    int nxt_x, nxt_y;
    if (imove == N * N)
        return 1;

    for (int k = 0; k < 8; k++) {
        nxt_x = x + xm[k];
        nxt_y = y + ym[k];

        if (isSafe(nxt_x, nxt_y, grid)) {
            grid[nxt_x][nxt_y] = imove;
            if (solveUtil(nxt_x, nxt_y, imove + 1, grid, xm, ym) == 1) {
                return 1;
            } else {
                grid[nxt_x][nxt_y] = -1;
            }
        }
    }
    return 0;
}

bool Solve() {
    int grid[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = -1;

    // int Xmove[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    // int Ymove[8] = {1, -1, 1, -1, 2, 2, -2, -2};

    int Xmove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int Ymove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    grid[0][0] = 0;

    if (solveUtil(0, 0, 1, grid, Xmove, Ymove) == 0) {
        cout << "Solution does not exist" << endl;
        return 0;
    } else
        printGrid(grid);

    return 1;
}

int main() {
    
    Solve();

    return 0;
}