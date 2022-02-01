import math

n = int(input())
lx = -1000000000000
rx = 1000000000000

for i in range(n):
    l, r = map(int, input().split())
    lx = max(lx, l)
    rx = min(rx, r)
    if lx <= rx:
        print(0)
    else:
        print(math.ceil(abs(lx - rx) / 2))