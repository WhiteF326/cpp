f = open("seed2.txt", "w")
start = 0
# write 1000 numbers from start to start + 1000
for i in range(1000):
    f.write(str(start + i) + "\n")
f.close()
