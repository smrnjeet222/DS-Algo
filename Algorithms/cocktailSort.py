def cocktail_sort(nums):
    for i in range(len(nums)-1, 0, -1):
        is_swapped = False

        for j in range(i, 0, -1):
            if nums[j]<nums[j-1]:
                nums[j], nums[j-1] = nums[j-1], nums[j] 
                is_swapped = True

        for j in range(len(nums)-i , i):
            if nums[j] > nums[j+1]:
                nums[j], nums[j+1] = nums[j+1], nums[j] 
                is_swapped = True

        if not is_swapped:
            return nums

arr = input('Input Numbers:\n').strip()
nums = [int(item) for item in arr.split(" ")]

print(cocktail_sort(nums))

