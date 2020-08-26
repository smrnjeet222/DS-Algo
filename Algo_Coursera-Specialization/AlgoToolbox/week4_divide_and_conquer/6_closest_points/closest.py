# Uses python3
import sys
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return str([self.x, self.y])


def distance(p1, p2):
    return ((p1.x - p2.x)**2 + (p1.y - p2.y)**2)**0.5


def cnstr_pts(x, y):
    pts = []
    for i in range(len(x)):
        pts.append(Point(x[i], y[i]))
    return pts


def minimum_distance(x, y):
    # write your code here
    pts = cnstr_pts(x, y)
    sorted_px = sorted(pts, key=lambda p: p.x)

    return lrg_min(sorted_px)


def sml_min(pts):
    result = sys.maxsize
    for i in range(len(pts)):
        for j in range(i+1, len(pts)):
            result = min(result, distance(pts[i], pts[j]))
    return result


def lrg_min(px):
    size = len(px)
    half_size = int(len(px)/2)

    if len(px) <= 3:
        return sml_min(px)

    lft_px = px[0:half_size]
    rght_px = px[half_size:size]

    lft_min = lrg_min(lft_px)
    rght_min = lrg_min(rght_px)

    sep_min = min(lft_min, rght_min)

    line_l = (lft_px[-1].x + rght_px[0].x)/2
    hybrd_min = compute_hybrd_min(lft_px, rght_px, line_l, sep_min)

    return min(sep_min, hybrd_min)


def compute_hybrd_min(lft_x, rght_x, line_l, wide):
    lft = []
    for i in range(len(lft_x)):
        if abs(lft_x[i].x - line_l) <= wide:
            lft.append(lft_x[i])

    rght = []
    for i in range(len(rght_x)):
        if abs(rght_x[i].x - line_l) <= wide:
            rght.append(rght_x[i])

    total = lft + rght

    total = sorted(total, key=lambda p: p.y)

    result = wide

    for i in range(len(total)):
        for j in range(i + 1, min(i+8, len(total))):
            if abs(total[i].y - total[j].y) <= wide:
                result = min(result, distance(total[i], total[j]))

    return result


if __name__ == '__main__':
    # input = sys.stdin.read()
    data = list(map(int, input().split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(x, y)))
