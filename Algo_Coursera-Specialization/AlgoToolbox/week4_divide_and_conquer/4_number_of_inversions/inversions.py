# Uses python3
import sys

def mrg_inv_cnt(a):
    if len(a)==1:
        return [0,a]

    mid = int(len(a)//2)
    lft = mrg_inv_cnt(a[0:mid])
    rght = mrg_inv_cnt(a[mid:])

    return merge(lft, rght)

def merge(lft, rght):
    cnt_inv = lft[0] + rght[0]
    lft_arr = lft[1]
    rght_arr = rght[1]

    rslt = []

    while len(lft_arr) > 0 and len(rght_arr) > 0:
        if lft_arr[0]>rght_arr[0]:
            rslt.append(lft_arr[0])
            cnt_inv += len(rght_arr)
            del (lft_arr[0])
        else:
            rslt.append(rght_arr[0])
            del(rght_arr[0])
    
    rslt += lft_arr
    rslt += rght_arr

    return [cnt_inv, rslt]

def get_number_of_inversions(a):
    [cnt_inv, srt_rslt] = mrg_inv_cnt(a)
    return cnt_inv


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    print(get_number_of_inversions(a))
