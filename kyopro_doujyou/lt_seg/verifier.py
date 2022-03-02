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
        self.n = n
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

    def max_right(self, l, f):
        if l == self.n:
            return self.n
        l += self.size
        sm = self.e()
        while 1:
            while l % 2 == 0:
                l >>= 1
            if f(self.op(sm, self.d[l])) == 0:
                while l < self.size:
                    l *= 2
                    if f(self.op(sm, self.d[l])):
                        sm = self.op(sm, self.d[l])
                        l += 1
                return l - self.size
            sm = self.op(sm, self.d[l])
            l += 1
            if (l & -l) == l:
                break
        return self.n

    def min_left(self, r, f):
        if r == 0:
            return 0
        r += self.size
        sm = self.e()
        while 1:
            r -= 1
            while r > 1 and (r % 2):
                r >>= 1
            if f(self.op(self.d[r], sm)) == 0:
                while r < self.size:
                    r = 2 * r + 1
                    if f(self.op(self.d[r], sm)):
                        sm = self.op(self.d[r], sm)
                        r -= 1
                return r + 1 - self.size
            sm = self.op(self.d[r], sm)
            if (r & -r) == r:
                break
        return 0

    def update(self, k):
        self.d[k] = self.op(self.d[2 * k], self.d[2 * k + 1])


def op(a, b):
    return max(a, b)


def e():
    return -1


target = 0


def f(v):
    return v < target


n, q = map(int, input().split())
a = list(map(int, input().split()))

seg = segtree(op, e, ary=a)

while q:
    q -= 1
    t, x, y = map(int, input().split())
    if t == 1:
        x -= 1
        seg.set(x, y)
    elif t == 2:
        x -= 1
        print(seg.prod(x, y))
    else:
        target = y
        x -= 1
        print(seg.max_right(x, f) + 1)
