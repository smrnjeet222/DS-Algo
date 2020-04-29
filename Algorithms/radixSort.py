def countingSort(arr, ep):
    n = len(arr)

    output = [0]*n
    count = [0]*10

    for i in range(n):
        idx = (arr[i]//ep)
        count[idx % 10] += 1

    for i in range(1, 10):
        count[i] += count[i-1]

    i = n-1
    while i >= 0:
        idx = (arr[i]//ep)
        output[count[idx % 10]-1] = arr[i]
        count[idx%10] -= 1
        i -= 1

    i=0
    for i in range(n):
        arr[i] = output[i]


def radixSort(arr):
    max1 = max(arr)
    ep = 1
    while max1/ep>0:
        countingSort(arr, ep)
        ep *=10

# ____________________________________

if __name__ == "__main__":
    arr = [2, 304, 2, 64, 800, 64, 304, 32, 58, 79, 4,
           5, 254, 27, 48, 653, 5, 24, 70, 598, 126]
    print("Given Array: ", arr)
    radixSort(arr)
    print("Sorted Array", arr)       