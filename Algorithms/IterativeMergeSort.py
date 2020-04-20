def mergeSort(arr):
    cur_sz = 1

    while cur_sz < len(arr)-1:
        lft = 0
        while lft < len(arr)-1:
            mid = lft + cur_sz-1
            
            rght = min(2*cur_sz + lft-1, len(arr)-1)
            if mid<len(arr)-1:
                merge(arr, lft, mid, rght)
            lft += cur_sz*2

        cur_sz *= 2


def merge(arr, l, m, r):
    n1 = m-l+1
    n2 = r-m

    L = [0]*n1
    R = [0]*n2

    for i in range(0, n1):
        L[i] = arr[l+i]
    for i in range(0, n2):
        R[i] = arr[m+i+1]

    i, j, k = 0, 0, l

    while i < n1 and j < n2:
        if L[i] > R[j]:
            arr[k] = R[j]
            j += 1
        else:
            arr[k] = L[i]
            i += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

# ________________________


if __name__ == "__main__":
    arr = [2, 4, 2, 64, 8, 64, 34, 32, 58, 79, 4,
           5, 25, 27, 48, 653, 5, 24, 7, 58, 264]

    print("Given Array: ", arr)
    mergeSort(arr)
    print("Sorted Array", arr)
