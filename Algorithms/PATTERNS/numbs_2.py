n = int(input("Enter Number: "))

print("One")
# 5 5 5 5 5
# 5 4 4 4 4
# 5 4 3 3 3
# 5 4 3 2 2
# 5 4 3 2 1

for i in range(1, n+1):
    for j in range(n, (n-i), -1):
        print(j, end=' ')
    print((str(n-i+1) + " ")*(n-i))

print()
# ----------------------------------------------
print("Two")
#           0
#         5 0 5
#       4 5 0 5 4
#     3 4 5 0 5 4 3
#   2 3 4 5 0 5 4 3 2
# 1 2 3 4 5 0 5 4 3 2 1

for i in range(0, n+1):
    print("  "*(n-i), end="")
    for j in range(-i, i+1):
        print(n-abs(j)+1 if j != 0 else 0, end=" ")
    print()

print()
# ----------------------------------------------
print("Two")
# 1
# 2 3 2
# 4 5 6 5 4
# 7 8 9 10 9 8 7
# 11 12 13 14 15 14 13 12 11
# 16 17 18 19 20 21 20 19 18 17 16

for i in range(1, n+1):
    t = int(((1+i)/2)*i)
    for j in range(-i+1, i):
        print(t-abs(j), end=" ")

    print()

print()
# ----------------------------------------------
print("Three")
# 1
# 2 7
# 3 8 13
# 4 9 14 19
# 5 10 15 20 25

for i in range(1, n+1):
    for j in range(0, i):
        print(n*j + i, end=' ')
    print()

print()
# ----------------------------------------------
print("Four")
# 1
# 2 3
# 4 5 6
# 7 8 9 10
# 11 12 13 14 15

x = 0
for i in range(n+1):
    for j in range(i):
        x += 1
        print(x, end=' ')
    print()

print()
# ----------------------------------------------
print("Five")
# 1
# 2 3
# 6 5 4
# 7 8 9 10
# 15 14 13 12 11

x = 1
for i in range(1, n+1):
    if i % 2 == 0:
        for j in range(i):
            print(x, end=' ')
            x += 1
    else:
        x += i
        for j in range(x, x-i, -1):
            print(j-1, end=' ')
    print()

print()
# ----------------------------------------------
print("Six")
# 1
# 2 3
# 4 5 6
# 7 8 9 10
# 11 12 13 14 15
# 16 17 18 19 20 21
# 22 23 24 25 26
# n==26
x = 1
mini = 1
while x <= n:
    j = 1
    while x <= n and j <= mini:
        print(x, end=' ')
        x += 1
        j += 1
    print()
    mini += 1

print()
# ----------------------------------------------
print("Six")
# 1  2  3  4  5
# 2  4  6  8  10
# 3  6  9  12 15
# 4  8  12 16 20
# 5  10 15 20 25

for i in range(1, n+1):
    for j in range(1, n+1):
        print("%-3d" % (j*i), end='')
    print()

print()
# ----------------------------------------------
print("Seven")
# 1 1 1 1 1 1 1
# 1 2 2 2 2 2 1
# 1 2 3 3 3 2 1
# 1 2 3 4 3 2 1
# 1 2 3 3 3 2 1
# 1 2 2 2 2 2 1
# 1 1 1 1 1 1 1

for i in range(-n+1, n):
    for j in range(-n+1, n):
        if abs(i) >= abs(j):
            print(n-abs(i), end=' ')
        else:
            print(n-abs(j), end=' ')
    print()

print()
# ----------------------------------------------
print("Eight")
#        0
#      1 0 1
#    2 1 0 1 2
#  3 2 1 0 1 2 3
#    2 1 0 1 2
#      1 0 1
#        0

for i in range(-n, n):
    print("  "*abs(i), end=' ')
    for j in range(-n+abs(i)+1, n-abs(i)):
        print(abs(j), end=" ")
    print()

print()
# ----------------------------------------------
print("Nine")
# 1 2 3 4 5 4 3 2 1
# 2 2 3 4 5 4 3 2 2
# 3 3 3 4 5 4 3 3 3
# 4 4 4 4 5 4 4 4 4
# 5 5 5 5 5 5 5 5 5
# 4 4 4 4 5 4 4 4 4
# 3 3 3 4 5 4 3 3 3
# 2 2 3 4 5 4 3 2 2
# 1 2 3 4 5 4 3 2 1

for i in range(-n+1, n):
    for j in range(-n+1, n):
        if abs(i) <= abs(j):
            print(n-abs(i), end=' ')
        else:
            print(n-abs(j), end=' ')
    print()

print()
# ----------------------------------------------
print("Ten")
# 1 2 3 4 5
# 5 1 2 3 4
# 4 5 1 2 3
# 3 4 5 1 2
# 2 3 4 5 1

for i in range(1, n+1):
    for j in range(1, n+1):
        print((j-i+1) if j >= i else (n-i+j+1), end=' ')
    print()

print()
# ----------------------------------------------
print("Eleven")
# 18                      9
# 18 14                7  9
# 18 14 10          5  7  9
# 18 14 10 6     3  5  7  9
# 18 14 10 6  2  3  5  7  9
# 18 14 10 6     3  5  7  9
# 18 14 10          5  7  9
# 18 14                7  9
# 18                      9

for i in range(-n+1, n):
    for j in range(-n+1, n):
        t = abs(j)*4 + 2
        if abs(j) < abs(i):
            print("  ", end=' ')
        else:
            if j <= 0:
                print("%-3d" % t, end='')
            else:
                print("%-3d" % (t//2), end='')
    print()

print()
# ----------------------------------------------
print("Twelve")
#             1
#          2 1 1 2
#       3 2 1   1 2 3
#    4 3 2 1     1 2 3 4
# 5 4 3 2 1       1 2 3 4 5
#    4 3 2 1     1 2 3 4
#       3 2 1   1 2 3
#          2 1 1 2
#             1

for i in range(-n+1, n):
    print("   "*abs(i), end='')
    for j in range(n-abs(i), 0, -1):
        print(j, end=" ")
    print("  "*(n-abs(i)-2), end="")
    for j in range(2 if abs(i)+1 == n else 1, n-abs(i) + 1):
        print(j, end=' ')
    print()
