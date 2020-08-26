# Uses python3
import sys


def optimal_weight_greedy(W, w):
    # write your code here
    result = 0
    for x in w:
        if result + x <= W:
            result = result + x
    return result


def optimal_weight(W, w):
    n = len(w)
    result = [[0 for x in range(W + 1)] for y in range(n + 1)]

    for i in range(1, n+1):
        for j in range(1, W+1):
            result[i][j] = result[i-1][j]
            if w[i-1] <= j:
                val = result[i-1][j - w[i-1]] + w[i-1]
                if val > result[i][j]:
                    result[i][j] = val

    return result[n][W]


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
