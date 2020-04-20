# A Bell Triangle is as this one- 
# 1
# 1 2
# 2 3 5
# 5 7 10 15
# 15 20 27 37 52
# 52 67 87 114 151 203

# The Bell Traingle is obtained by beginning the first row with 1 and beginning subsequent rows with last number of the previous row. 
# Rows are filled out by adding the number in the preceding column to the number above it. Eg. in third row 2+(number above it i.e. 1)=3...The pattern follows on similarly


n = int(input("Enter No. "))

def bellNum(n):
    bell = [[0 for i in range(n+1)] for j in range(n+1)]
    bell[0][0] = 1
    print(1)
    for i in range(1, n+1):
        bell[i][0]=bell[i-1][i-1]
        print(bell[i][0], end=' ')
        for j in range(1, i+1):
            bell[i][j] = bell[i-1][j-1] + bell[i][j-1]
            print(bell[i][j] , end=' ')
        print()
    return 

bellNum(n-1)