def partiton(arr, low, high):
    i = low
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i = i+1
        
    arr[i], arr[high] = arr[high], arr[i]
    return i 

def quickSort(arr, low, high):
    if low<high:
        pi = partiton(arr, low, high)

        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

if __name__ == "__main__":
    arr = [2, 4, 2, 64, 8, 64, 34, 32, 58, 79, 4,
           5, 25, 27, 48, 653, 5, 24, 7, 58, 26]
    n = len(arr)
    print("Given Array: ", arr)
    quickSort(arr, 0, n-1)
    print("Sorted Array", arr)       

