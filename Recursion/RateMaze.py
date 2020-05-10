import numpy as np

N = 5


def isSafe(maze, x, y):
    if x >= 0 and x < N and y >= 0 and y < N and maze[x][y] == 0:
        return True
    return False


def solveMaze(maze):
    sol = np.zeros([N, N], dtype=int)

    if solveMazeUtil(maze, 0, 0, sol) == False:
        print("No Path exist")
        return False
    print(np.matrix(sol))
    return True


def solveMazeUtil(maze, x, y, sol):
    if x == N - 1 and y == N - 1 and maze[x][y] == 0:
        sol[x][y] = 1
        return True
    if isSafe(maze, x, y):
        sol[x][y] = 1
        if solveMazeUtil(maze, x + 1, y, sol):
            return True 
        if solveMazeUtil(maze, x, y + 1, sol):
            return True

        sol[x][y] = 0
        return False


if __name__ == "__main__":
    maze = [[0, 0, 0, 1, 0],
            [1, 0, 0, 0, 0],
            [0, 0, 1, 0, 0],
            [0, 1, 0, 0, 1],
            [1, 1, 0, 0, 0]]

    solveMaze(maze)