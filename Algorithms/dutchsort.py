arr = [1,1,0,2,2,1,2,0,0,0,2,2]

def dutchsort(arr):
    low = 0
    high = len(arr) - 1  
    idx = 0
    while idx <= high:
        if arr[idx] == 1:
            idx += 1
        elif arr[idx] == 0:
            arr[low], arr[idx] = arr[idx], arr[low]
            low += 1
            idx += 1
        else:
            arr[idx], arr[high] = arr[high], arr[idx]
            high -= 1
    return arr

print(dutchsort(arr))

