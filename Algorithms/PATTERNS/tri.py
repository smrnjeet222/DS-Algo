n = int(input("Enter Number : "))
print("one")
#     *
#    * *
#   * * *
#  * * * *
# * * * * *

for i in range(1, n+1):
    print(" "*(n-i) + "* "*i)

print()
# -------------------------------------------
print("two")
#  * * * * * *
#   * * * * *
#    * * * *
#     * * *
#      * *
#       *

for i in range(n+1):
    print(" "*i + " *"*(n-i))

print()
# -------------------------------------------
print("three")
# * * * * * *
#   * * * * *
#     * * * *
#       * * *
#         * *
#           *

for i in range(n+1):
    print("  "*i + "* "*(n-i))

print()
# -------------------------------------------
print("four")
#           *
#         * * *
#       * * * * *
#     * * * * * * *
#   * * * * * * * * *
# * * * * * * * * * * *

x = n*2
for i in range(1, x+1, 2):
    print(" "*(x - i - 1) + "* "*i)

print()
# -------------------------------------------
print("five")
# *
# **
# ***
# ****
# *****
# ******
# *****
# ****
# ***
# **
# *

for i in range(-n+1, n):
    print("*"*(n-abs(i)))

print()
# -------------------------------------------
print("six")
#           **
#         ******
#       **********
#     **************
#   ******************
# **********************

for i in range(1, n+1):
    print("  "*(n - i) + "**"*(i*2 - 1))

print()
# -------------------------------------------
