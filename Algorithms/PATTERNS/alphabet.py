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

print()
# ___________________________________________
print("Seven")
# Aa
# AaBb
# AaBbCc
# AaBbCcDd
# AaBbCcDdEe

for i in range(1, n+1):
    for j in range(1, i+1):
        print(chr(j+64)+chr(j+96), end='')
    print()

print()
# ___________________________________________
print("Eight")
#     A
#    B C
#   D E F
#  G H I J
# K L M N O

c = 0
for i in range(1, n+1):
    print(" "*(n-i), end="")
    for j in range(1, i+1):
        print(chr((c % 26)+65), end=" ")
        c += 1
    print()

print()
# ___________________________________________
print("Nine")
#     A
#    a a
#   B B B
#  b b b b
# C C C C C
#  c c c c
#   D D D
#    d d
#     E

c = 1
for i in range(-n+1, n):
    print(" "*(abs(i)), end='')
    if c % 2:
        print((chr(c//2+65) + " ")*(n-abs(i)))
    else:
        print((chr(c//2+96) + " ")*(n-abs(i)))
    c += 1

print()
# ___________________________________________
print("Ten")
# A B C
#  Z Y
# A B
#  Z
# A
#  Z
# A B
#  Z Y
# A B C

for i in range(-n+1, n):
    x = abs(i)+1
    for j in range((2-x % 2), x+1, 2):
        if x % 2:
            print(chr(j//2+65), end=' ')
        else:
            print(" " + chr(91-j//2), end='')
    print()
