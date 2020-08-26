# Uses python3
import sys
import numpy as np


def lcs3(a, b, c):
    # write your code here
    matrix = np.zeros(shape=(len(a)+1, len(b)+1, len(c)+1), dtype=int)

    for i in range(len(a) + 1):
        for j in range(len(b) + 1):
            for k in range(len(c) + 1):
                if i == 0 or j == 0 or k == 0:
                    matrix[i][j][k] = 0
                elif a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1]:
                    matrix[i][j][k] = matrix[i - 1][j - 1][k-1] + 1
                else:
                    matrix[i][j][k] = max(max(matrix[i-1][j][k],
                                              matrix[i][j-1][k]),
                                          matrix[i][j][k-1])

    return matrix[len(a)][len(b)][len(c)]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))

    # print(lcs3("003200", "003200", "003200"))
