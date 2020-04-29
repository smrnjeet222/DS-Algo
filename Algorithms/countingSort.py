def countSort(arr):
    count = [0]*256
    output = [0]*len(arr)

    for i in arr:
        count[ord(i)] += 1

    for i in range(256):
        count[i] += count[i-1]

    for i in range(len(arr)):
        output[count[ord(arr[i])]-1] = arr[i]
        count[ord(arr[i])] -=1
    
    return output

# _________________________________

if __name__ == "__main__":
    arr = "geeksforgeeks"
    print(f"Given String:  {arr}")
    ans = countSort(arr)
    print("Sorted String:", ("".join(ans)))  