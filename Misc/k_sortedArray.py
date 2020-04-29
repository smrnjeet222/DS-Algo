from heapq import heapify, heappop, heappush

def sort_k(arr: list,n:int , k:int):
    heap = arr[ :k+1]

    heapify(heap)

    t_idx = 0

    for rem_elem_idx in range(k+1, n):
        arr[t_idx] = heappop(heap)
        heappush(heap, arr[rem_elem_idx])
        t_idx += 1

    while heap:
        arr[t_idx] = heappop(heap)
        t_idx += 1

arr = [2, 6, 3, 12, 56, 8, 20, 31, 77, 40] 

sort_k(arr, len(arr), 3)

print("\nNearly Sorted to Sorted:", arr)



