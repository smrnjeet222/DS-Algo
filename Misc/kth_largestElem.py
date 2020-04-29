# randomised QuickSelect(Expected Linear Time)
import random


def kthlargest(arr, l, r, k):
    if k > 0 and k <= r-l+1:
        pos = partition(arr, l, r)

        if pos-l == k-1:
            return arr[pos]
        if pos-l > k-1:
            return kthlargest(arr, l, pos-1, k)

        return kthlargest(arr, pos+1, r, k-pos+l-1)

    return None


def partition(arr, l, r):
    pivot = int(random.random() % (r-l+1))
    x = arr[pivot]
    i = l
    for j in range(l, r):
        if arr[j] >= x:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[pivot] = arr[pivot], arr[i]
    return i

# _________________________


if __name__ == '__main__':

    arr = [12, 3, 5, 7, 4, 19, 26]
    n = len(arr)
    k = 3
    print("\nK'th Largest element is",
          kthlargest(arr, 0, n - 1, k))

    print("\nK'th Smallest element is",
          kthlargest(arr, 0, n - 1, n-k+1))
