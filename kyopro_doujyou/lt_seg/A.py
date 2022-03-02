def ceil_pow2(n):
    x = 0
    while((1 << x) < n):
        x += 1
    return x


class segtree:
    def __init__(self, op, e, n=0, ary=[]):
        self.op = op
        self.e = e
        if n:
            ary = [e()] * n
        else:
            n = len(ary)
        self.log = ceil_pow2(n)
        self.size = 1 << self.log
        self.d = [e()] * (2 * self.size)
        for i in range(n):
            self.d[self.size + i] = ary[i]
        for i in reversed(range(1, self.size)):
            self.update(i)

    def set(self, p, x):
        p += self.size
        self.d[p] = x
        for i in range(1, self.log + 1):
            self.update(p >> i)

    def get(self, p):
        return self.d[p + self.size]

    def prod(self, l, r):
        sml = self.e()
        smr = self.e()
        l += self.size
        r += self.size

        while l < r:
            if l & 1:
                sml = self.op(sml, self.d[l])
                l += 1
            if r & 1:
                r -= 1
                smr = self.op(self.d[r], smr)
            l >>= 1
            r >>= 1

        return self.op(sml, smr)

    def all_prod(self):
        return self.d[1]

    def update(self, k):
        self.d[k] = self.op(self.d[2 * k], self.d[2 * k + 1])


def op(a, b):
    return a | b


def e():
    return 0


n = int(input())
s = input()
p = [(1 << (ord(s[i]) - ord("a"))) for i in range(n)]

seg = segtree(op, e, ary=p)


def popcount(v):
    res = 0
    while v:
        res += v & 1
        v >>= 1
    return res


q = int(input())
while q:
    q -= 1
    t, x, y = input().split()
    if int(t) == 1:
        i = int(x)
        c = ord(y) - ord("a")
        seg.set(i - 1, 1 << c)
    else:
        l, r = map(int, [x, y])
        print(popcount(seg.prod(l - 1, r)))
