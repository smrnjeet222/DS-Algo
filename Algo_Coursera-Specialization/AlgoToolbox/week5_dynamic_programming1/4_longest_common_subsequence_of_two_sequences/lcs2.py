# Uses python3

import sys
import numpy as np


def lcs2(a, b):
    # write your code here
    matrix = np.zeros(shape=(len(a)+1, len(b)+1), dtype=int)

    for i in range(len(a) + 1):
        for j in range(len(b) + 1):
            if i == 0 or j == 0:
                matrix[i][j] = 0
            elif a[i - 1] == b[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1])

    return matrix[len(a)][len(b)]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))

    # print(lcs2("2783", "5287"))
