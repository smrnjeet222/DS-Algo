def partiton(arr, low, high):
    i = low
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i = i+1
        
    arr[i], arr[high] = arr[high], arr[i]
    return i 

def quickSortIt(arr, low, high):
    sz = high-low+1
    st = [0]*sz

    top=-1

    top += 1
    st[top] = low
    top += 1
    st[top] = high

    while top>0:

        h = st[top]
        top-=1
        l = st[top]
        top-=1

        p = partiton(arr, l, h)

        if p-1>l:
            top += 1
            st[top] = l
            top += 1
            st[top] = p-1

        if p+1<h:
            top += 1
            st[top] = p+1
            top += 1
            st[top] = h

# _________________________________

if __name__ == "__main__":
    arr = [2, 4, 2, 64, 8, 64, 34, 32, 58, 79, 4,
           5, 25, 27, 48, 653, 5, 24, 7, 58, 26]
    n = len(arr)
    print("Given Array: ", arr)
    quickSortIt(arr, 0, n-1)
    print("Sorted Array", arr)       
