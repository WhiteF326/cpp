import random

f = open("./input.txt", "w")
f.write("2\n")
for _ in range(2):
    f.write("10000\n")
    f.write(" ".join(str(i) for i in range(1, 10001)) + "\n")