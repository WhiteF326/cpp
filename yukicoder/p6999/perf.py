f = open("perf3.txt", mode='w')
n = 40
dex = []

for i in range(n - 1):
    for j in range(i + 1, n):
        dex.append(str(i + 1) + " " + str(j + 1))

f.write(str(n) + " " + str(len(dex)))
f.write("\n")
for s in dex:
    f.write(s)
    f.write("\n")
f.close()