from math import sqrt


def solve(bo):
    find = find_empty(bo)
    if not find:
        return False
    else:
        row, col = find

    for i in range(1, 10):
        if valid(bo, i, (row, col)):
            bo[row][col] = i
            solve(bo)
            bo[row][col] = 0
    return True


def valid(bo, num, pos):

    for i in range(len(bo[0])):
        if bo[pos[0]][i] == num and pos[1] != i:
            return False

    for i in range(len(bo)):
        if bo[i][pos[1]] == num and pos[0] != i:
            return False

    x = int(sqrt(len(bo[0])))
    y = int(sqrt(len(bo)))

    box_x = pos[1]//x
    box_y = pos[0]//y

    for i in range(box_y * x, box_y*x + x):
        for j in range(box_x * y, box_x*y + y):
            if bo[i][j] == num and (i, j) != pos:
                return False

    return True


def find_empty(bo):

    for i in range(len(bo)):
        for j in range(len(bo[0])):
            if bo[i][j] == 0:
                return(i, j)
    print_board(bo)
    input("\nMore?\t")
    return None


def print_board(bo):
    print()
    x = int(sqrt(len(bo[0])))
    y = int(sqrt(len(bo)))
    for i in range(len(bo)):
        if i % y == 0 and i != 0:
            print("-----------------------")
        for j in range(len(bo[0])):
            if j % x == 0 and j != 0:
                print(" |", end='')

            if j == (len(bo[0])-1):
                print(" " + str(bo[i][j]))
            else:
                print(" " + str(bo[i][j]), end='')
    return


# _____________________________________________

# board = [
#     [8, 0, 0, 0, 0, 0, 0, 0, 0],
#     [0, 0, 3, 6, 0, 0, 0, 0, 0],
#     [0, 7, 0, 0, 9, 0, 2, 0, 0],
#     [0, 5, 0, 0, 0, 7, 0, 0, 0],
#     [0, 0, 0, 0, 4, 5, 7, 0, 0],
#     [0, 0, 0, 1, 0, 0, 0, 3, 0],
#     [0, 0, 1, 0, 0, 0, 0, 6, 8],
#     [0, 0, 8, 5, 0, 0, 0, 1, 0],
#     [0, 9, 0, 0, 0, 0, 4, 0, 0]
# ]

# solve(board)

grid = [
    [7, 8, 0, 4, 0, 0, 1, 0, 0],
    [6, 0, 0, 0, 7, 5, 0, 0, 9],
    [0, 0, 0, 6, 0, 1, 0, 7, 8],
    [0, 0, 7, 0, 4, 0, 2, 6, 0],
    [0, 0, 1, 0, 0, 0, 9, 3, 0],
    [0, 0, 4, 0, 6, 0, 0, 0, 5],
    [0, 7, 0, 3, 0, 0, 0, 1, 2],
    [1, 2, 0, 0, 0, 7, 4, 0, 0],
    [0, 4, 0, 0, 0, 6, 0, 0, 0]
]

solve(grid)
