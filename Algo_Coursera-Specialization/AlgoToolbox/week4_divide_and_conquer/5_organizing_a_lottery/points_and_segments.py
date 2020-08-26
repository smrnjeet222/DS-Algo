# Uses python3
import sys


def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    # write your code here
    L = 1
    P = 2
    R = 3

    s_l = [L] * len(starts)
    e_r = [R] * len(ends)
    p_p = [P] * len(points)

    pairs_num = starts + ends + points
    pairs_let = s_l + e_r + p_p

    x = sorted(list(zip(pairs_num, pairs_let)))

    pairs_num, pairs_let = [ i for i, j in x ], [ j for i, j in x ]

    count_left = 0

    point_counts = {}
    for p in points:
        point_counts[p] = 0

    for i in range(len(pairs_num)):
        if pairs_let[i] == L:
            count_left += 1
        elif pairs_let[i] == R:
            count_left -= 1
        elif pairs_let[i] == P:
            if point_counts[pairs_num[i]] == 0:
                point_counts[pairs_num[i]] += count_left

    for i in range(len(points)):
        cnt[i] = point_counts[points[i]]

    return cnt


def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    # use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
