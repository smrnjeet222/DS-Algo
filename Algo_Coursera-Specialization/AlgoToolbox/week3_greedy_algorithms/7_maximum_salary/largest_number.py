# Uses python3
n = int(input())
lst = [int(i) for i in input().split()]


def IsG(dg, mx_dg):
    return int(str(dg)+str(mx_dg)) >= int(str(mx_dg)+str(dg))


def largestnumber(lst):
    ans = []
    while lst:
        mx_dg = 0
        for dg in lst:
            if IsG(dg, mx_dg):
                mx_dg = dg
        ans.append(mx_dg)
        lst.remove(mx_dg)

    return ans


print(''.join([str(i) for i in largestnumber(lst)]))
