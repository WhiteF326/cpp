import bisect
import math
import sys

sys.setrecursionlimit(1 << 20)

class SegTree:
    def __init__(self, n):
        nx = n
        self.el = 1
        self.h = 0
        while nx:
            nx >>= 1
            self.h += 1
            self.el <<= 1
        self.s = self.el << 1
        self.val = [0 for _ in range(self.s)]
    
    def get(self, p):
        return self.val[p + self.el - 1]
    def set(self, p, st):
        xp = p + self.el + 1
        self.val[xp] = st
        while xp > 0:
            xp = (xp - 1) // 2
            self.val[xp] = self.merge(self.val[xp * 2 + 1], self.val[xp * 2 + 2])
    
    def product(self, l, r):
        return self.product_sub(l, r, 0, self.s)
    def product_sub(self, l, r, a, b):
        if b <= l or r <= a:
            return self.e()
        elif l <= a and b <= r:
            range = int(self.h - math.log2(b - a))
            sl = (a / (b - 1)) + (1 << range) - 1
            return self.val[int(sl)]
        else:
            ql = self.product_sub(l, r, a, (a + b) / 2)
            qr = self.product_sub(l, r, (a + b) / 2, b)
            return self.merge(ql, qr)
    
    def merge(self, a, b):
        return a + b
    def e(self):
        return 0

n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
itm = [[b[i], -a[i]] for i in range(n)]

itm = sorted(itm)
for i in range(n):
    itm[i][0], itm[i][1] = -itm[i][1], itm[i][0]
    itm[i][0] = bisect.bisect_left(a, itm[i][0])
    itm[i][1] = bisect.bisect_left(b, itm[i][1])

ans = 0
cont = 0

seg = SegTree(n)

for i in range(n):
    x = itm[i]
    if i:
        if x[0] == itm[i - 1][0] and x[1] == itm[i - 1][1]:
            cont += 1
        else:
            cont = 0
    print(x[0])
    seg.set(x[0], seg.get(x[0]) + 1)
    ans += seg.product(x[0], n) + cont

print(ans)
