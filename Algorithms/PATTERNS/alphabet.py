n = int(input("Enter Number: "))

print("One")
# A
# B A
# C B A
# D C B A
# E D C B A
# F E D C B A
# G F E D C B A

for i in range(1, n+1):
    for j in range(i, 0, -1):
        print(chr(j+64), end=" ")
    print()

print()
# ___________________________________________
print("Two")
# A
# B b
# C c C
# D d D d
# E e E e E
# F f F f F f
# G g G g G g G
for i in range(1, n+1):
    for j in range(1, i+1):
        if j % 2:
            print(chr(i+64), end=" ")
        else:
            print(chr(i+96), end=" ")
    print()

print()
# ___________________________________________
print("Three")
#            A
#          B A B
#        C B A B C
#      D C B A B C D
#    E D C B A B C D E
#  F E D C B A B C D E F

for i in range(1, n+1):
    print("  "*(n-i), end=" ")
    for j in range(-i+1, i):
        print(chr(abs(j)+65), end=" ")
    print()

print()
# ___________________________________________
print("Four")
#            A
#          A B A
#        A B C B A
#      A B C D C B A
#    A B C D E D C B A
#  A B C D E F E D C B A
for i in range(1, n+1):
    print("  "*(n-i), end=" ")
    for j in range(-i+1, i):
        print(chr(i-abs(j)+64), end=" ")
    print()

print()
# ___________________________________________
print("Five")
#  A B C D E
#   B C D E
#    C D E
#     D E
#      E

for i in range(1, n+1):
    print(" "*(i-1), end=" ")
    for j in range(1, (n-i)+1):
        print(chr(j+63+i), end=" ")
    print()

print()
# ___________________________________________
print("Six")
# A 1 1 1 1 1 1
# 0 B 1 1 1 1 1
# 0 0 C 1 1 1 1
# 0 0 0 D 1 1 1
# 0 0 0 0 E 1 1
# 0 0 0 0 0 F 1
# 0 0 0 0 0 0 G

for i in range(0, n):
    print("0 "*i + chr(i+65) + " 1"*(n-i-1))

