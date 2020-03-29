n = int(input("Enter Number: "))

print("One")
# 1
# 2 1
# 3 2 1
# 4 3 2 1
# 5 4 3 2 1
# 6 5 4 3 2 1
# 7 6 5 4 3 2 1

for i in range(1, n+1):
    for j in range(1, i+1):
        print(i-j+1, end=" ")
    print()

print()
# ----------------------------------------------
print("Two")
# 7
# 6 7
# 5 6 7
# 4 5 6 7
# 3 4 5 6 7
# 2 3 4 5 6 7
# 1 2 3 4 5 6 7

for i in range(1, n+1):
    for j in range(1, i+1):
        print(n-(i-j), end=" ")
    print()

print()
# ----------------------------------------------
print("Three")
#       7
#      6 6
#     5 5 5
#    4 4 4 4
#   3 3 3 3 3
#  2 2 2 2 2 2
# 1 1 1 1 1 1 1

for i in range(1, n+1):
    for j in range(1, n+1):
        if j < (n-i+1):
            print(" ", end="")
        else:
            print(n-i+1, end=" ")
    print()

print()
# ----------------------------------------------
print("Four")
#  1 2 3 4 5 6 7
#   1 2 3 4 5 6
#    1 2 3 4 5
#     1 2 3 4
#      1 2 3
#       1 2
#        1

for i in range(1, n+1):
    print(" "*i, end="")
    for j in range(n, i-1, -1):
        print(n-j+1, end=" ")
    print()

print()
# ----------------------------------------------
print("Five")
# 1 0 0 0 0 0 0
# 0 2 0 0 0 0 0
# 0 0 3 0 0 0 0
# 0 0 0 4 0 0 0
# 0 0 0 0 5 0 0
# 0 0 0 0 0 6 0
# 0 0 0 0 0 0 7

for i in range(1, n+1):
    for j in range(1, n+1):
        if i == j:
            print(j, end=" ")
        else:
            print(0, end=" ")
    print()

print()
# ----------------------------------------------
print("Six")
# 1 1 1 1 1 1 1
# 1 1 1 1 1 2 2
# 1 1 1 1 3 3 3
# 1 1 1 4 4 4 4
# 1 1 5 5 5 5 5
# 1 6 6 6 6 6 6
# 7 7 7 7 7 7 7

for i in range(1, n+1):
    for j in range(1, n+1):
        if j <= (n-i):
            print(1, end=" ")
        else:
            print(i, end=" ")
    print()

print()
# ----------------------------------------------
print("Seven")
# 4 3 2 1
# 3 2 1
# 2 1
# 1
# 1
# 2 1
# 3 2 1
# 4 3 2 1

for i in range(-n, n+1):
    if i != 0:
        for j in range(1, abs(i)+1):
            print(abs(i)-j+1, end=" ")
        print()

print()
# ----------------------------------------------
print("Eight")
# 1 2 3 4 5
#  2 3 4 5
#   3 4 5
#    4 5
#     5
#     5
#    4 5
#   3 4 5
#  2 3 4 5
# 1 2 3 4 5

for i in range(-n, n+1):
    if i != 0:
        print(" "*(n-abs(i)), end="")
        for j in range(1, abs(i)+1):
            print(n-(abs(i)-j+1)+1, end=" ")
        print()

print()
# ----------------------------------------------
print("Nine")
#          1
#        1 2 1
#      1 2 3 2 1
#    1 2 3 4 3 2 1
#  1 2 3 4 5 4 3 2 1

for i in range(1, n+1):
    print("  "*(n-i) , end=" ")
    for j in range(-i+1, i):
        print(i-abs(j), end=" ")

    print()

print()
# ----------------------------------------------
print("Ten")
# 1 2 3 4 5 4 3 2 1
# 2 3 4 5 4 3 2
# 3 4 5 4 3
# 4 5 4
# 5

for i in range(1, n+1):
    for j in range(-n+i, n-i+1):
        print(n-abs(j), end=" ")

    print()

print()
# ----------------------------------------------
print("Eleven")
# 1
# 2 2
# 3 3 3
# 4 4 4 4
# 3 3 3
# 2 2
# 1

for i in range(-n+1, n):
    for j in range(1, n-abs(i)+1):
        print(n-abs(i), end=" ")

    print()

print()
# ----------------------------------------------
print("Twelve")
# 4
# 3 4 3
# 2 3 4 3 2
# 1 2 3 4 3 2 1
# 2 3 4 3 2
# 3 4 3
# 4

for i in range(-n+1, n):
    for j in range(-(n-abs(i))+1, n-abs(i)):
        print(n-abs(j), end=" ")

    print()

print()
# ----------------------------------------------
print("Thirteen")
#      1
#     1 2
#    1 2 3
#   1 2 3 4
#  1 2 3 4 5
#   1 2 3 4
#    1 2 3
#     1 2
#      1

for i in range(-n+1 , n):
    print(" "*abs(i) , end=" ")
    for j in range(1, n-abs(i)+1):
        print(j , end=" ")
    
    print()
print()
# ----------------------------------------------
print("Fourteen")
# 1             1
# 1 2         2 1
# 1 2 3     3 2 1
# 1 2 3 4 4 3 2 1

for i in range(1,n+1):
    for j in range(-n , n+1):
        if (n-abs(j)+1)<=i:
            print(n-abs(j)+1, end=" ")
        elif j!=0:
            print(" ", end=" ")
    print()

print()
# ----------------------------------------------
print("Fifthteen")
# 1 2 3 4 5 4 3 2 1
# 1 2 3 4   4 3 2 1
# 1 2 3       3 2 1
# 1 2           2 1
# 1               1

for i in range(n,0,-1):
    for j in range(-n+1, n):
        if n-abs(j) <= i:
            print(n-abs(j), end=" ")
        else :
            print(" ",end=" ")

    print()


