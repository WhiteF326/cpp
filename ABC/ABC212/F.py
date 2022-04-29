p = int(input())

st = [set() for _ in range(p)]

for x in range(p):
    for y in range(p):
        for n in range(1, p):
            if pow(x, n, p) == y:
                st[x].add(y)

for i in range(p):
    for s in st[i]:
        print(i, s)