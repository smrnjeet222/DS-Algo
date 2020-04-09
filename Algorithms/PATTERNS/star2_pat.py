n = int(input("Enter Number: "))

print("One")
#    *
#   * *
#  * * *
# * * * *
#  * * *
#   * *
#    *

for i in range(-n+1, n):
    print(" "*abs(i) + "* "*(n-abs(i)))

print()
# -------------------------------------------
print("Two")
#    *
#   * *
#  *   *
# *     *
#  *   *
#   * *
#    *

for i in range(-n+1, n):
    if abs(i) == abs(-n+1):
        print(" "*abs(i) + "*")
    else:
        print(" "*abs(i) + "*" + " "*((n-abs(i))*2-3) + "*")

print()
# -------------------------------------------
print("Three")
#    *
#   * *
#  *   *
# * * * *
#  *   *
#   * *
#    *

for i in range(-n+1, n):
    if abs(i) == abs(-n+1):
        print(" "*abs(i) + "*")
    elif i == 0:
        print("* "*n)
    else:
        print(" "*abs(i) + "*" + " "*((n-abs(i))*2-3) + "*")

print()
# -------------------------------------------
print("Four")
#    *
#    *
#    *
# * * * *
#    *
#    *
#    *

for i in range(1, n*2):
    if i == n:
        print("* "*n)
    else:
        print(" "*(n-1) + "*")

print()
# -------------------------------------------
print("Five")
#     *
#    * *
#   * * *
#  *  *  *
# * * * * *
#  *  *  *
#   * * *
#    * *
#     *

for i in range(-n+1, n):
    if i == 0:
        print("* "*n)
    elif abs(i) == abs(-n+1):
        print(" "*abs(i) + "*")
    elif abs(i) == abs(-n+2):
        print(" "*abs(i) + "*" + " "*((n-abs(i))*2-3) + "*")
    else:
        print(" "*abs(i) + "*" + " "*(n-abs(i)-2) + "*" + " "*(n-abs(i)-2) + "*")

print()
# -------------------------------------------
print("Six")
#       *
#     **
#   ***
# ****
#   ***
#     **
#       *

for i in range(-n+1, n):
    print("  "*abs(i) + "*"*(n-abs(i)))

print()
# -------------------------------------------
print("Seven")
# * * * * *
# *       *
# *       *
# *       *
# * * * * *
for i in range(n):
    if(i == 0 or i == (n-1)):
        print("* "*n)
    else:
        print("*" + " "*(2*n - 3) + "*")

print()
# -------------------------------------------
print("Eight")
# * * * * * *
# *    *    *
# *    *    *
# *    *    *
# *    *    *
# * * * * * *

for i in range(n):
    for j in range(n):
        if i == 0 or i == (n-1) or j == 0 or j == (n-1):
            print("* ", end="")
        elif n % 2 == 1 and j == int(n/2):
            print("* ", end="")
        elif n % 2 == 0 and j == ((n/2)-1):
            print(" *", end="")
        else:
            print("  ", end="")
    print()

print()
# -------------------------------------------
print("Nine")
# * * * * * * *
# *     *     *
# *     *     *
# * * * * * * *
# *     *     *
# *     *     *
# * * * * * * *

for i in range(n):
    if i == 0 or i == (n-1) or i == (n-1)//2:
        print("* "*n)
    else:
        print("*" + " "*(n-2) + "*", end="")
        print(" "*(n-2) + "*", end="")
        print()

print()
# -------------------------------------------
print("Ten")
# * * * * * * * * * * * * *
# *                       *
# *   * * * * * * * * *   *
# *   *               *   *
# *   *   * * * * *   *   *
# *   *   *       *   *   *
# *   *   *   *   *   *   *
# *   *   *       *   *   *
# *   *   * * * * *   *   *
# *   *               *   *
# *   * * * * * * * * *   *
# *                       *
# * * * * * * * * * * * * *

x = n*2
for i in range(-x, x+1):
    for j in range(-x, x+1):
        if(abs(j) % 2 == 0 and abs(i) <= abs(j)) or (abs(j) <= abs(i) and abs(i) % 2 == 0):
            print("* ", end="")
        else:
            print("  ", end="")
    print("")


print()
# -------------------------------------------

