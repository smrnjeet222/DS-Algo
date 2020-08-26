# Uses python3
import sys
from collections import Counter

def get_majority_element(a, left, right):
    cntr = Counter(a)
    ans =  cntr.most_common(1)[0][1]
    if ans > (left+right)//2:
        return ans
    else:
        return -1


if __name__ == '__main__':
    n  = int(input())
    a = list(map(int, input().split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
