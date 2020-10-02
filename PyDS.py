import os
import platform

print(os.system("date"))

print("Platform: ", platform.platform())
print("System: ", platform.system())
print("Architecture: ", platform.architecture())
print("Machine: ", platform.machine())
print("Processor: ", platform.processor())

listvar = ["apple", "google", "blackberry", "google"]
tuplevar = ("apple", "google", "blackberry", "google")
mySet = {"apple", "google", "blackberry", "google"}

E = listvar[1] = "Microsoft"
new = listvar[3]
listvar.append('append')  # insert at last
listvar.insert(1, 'insert')  # insert at given possition
print(listvar)

print()
print("TUPPLE..... ")
E = tuplevar[1]  # = "Microsoft"  Can't assign
new = tuplevar[3]
print(new)
print(E)

print()
print("SET.....")

print(mySet)
mySet.add("stuffff")
mySet.update(["Microsoft", "setadd"])

print(mySet)
mySet.remove("google")
mySet.discard("stuffff")
print(mySet)

# 2D LISTS

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
# for row in matrix:
#     for item in row:
#         print(item)
