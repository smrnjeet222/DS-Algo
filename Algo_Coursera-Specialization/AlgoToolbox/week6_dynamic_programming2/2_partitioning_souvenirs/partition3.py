# Uses python3
import sys
import itertools


def partition3(A):
    total = sum(A)
    if len(A) < 3 or total % 3:
        return False
    br = total // 3
    table = [[0] * (len(A) + 1) for _ in range(br + 1)]

    for i in range(1, br + 1):
        for j in range(1, len(A) + 1):
            num = i - A[j - 1]
            if A[j - 1] == i or (num > 0 and table[num][j - 1]):
                table[i][j] = 1 if table[i][j - 1] == 0 else 2
            else:
                table[i][j] = table[i][j - 1]

    return True if table[-1][-1] == 2 else False


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(partition3(A))
