def Heap(nums, index, heap_size):
    largest_num = index
    lft_idx = 2*index+1
    rght_idx = 2*index+2
    if rght_idx < heap_size and nums[rght_idx] > nums[largest_num]:
        largest_num = rght_idx

    if lft_idx < heap_size and nums[lft_idx] > nums[largest_num]:
        largest_num = lft_idx        

    if largest_num != index:
        nums[largest_num], nums[index] = nums[index], nums[largest_num]
        Heap(nums, largest_num, heap_size)

def heap_sort(nums):
    n = len(nums)
    # Creating max Heap
    for i in range(n//2 - 1, -1, -1):
        Heap(nums, i, n)
    # sort
    for i in range(n-1, 0, -1):
        # print (nums)
        nums[0], nums[i] = nums[i] , nums[0]
        Heap(nums, 0, i)

# _________________________

arr = input("Input Numbers:\n").strip()

nums = [int(item) for item in arr.split(" ")]

heap_sort(nums)

print(nums)


