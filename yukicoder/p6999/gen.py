class DSU:
    def __init__(self, n):
        self._n = n
        self.parent_or_size = [-1] * n

    def merge(self, a, b):
        assert 0 <= a < self._n
        assert 0 <= b < self._n
        x, y = self.leader(a), self.leader(b)
        if x == y: return x
        if -self.parent_or_size[x] < -self.parent_or_size[y]: x, y = y, x
        self.parent_or_size[x] += self.parent_or_size[y]
        self.parent_or_size[y] = x
        return x

    def same(self, a, b):
        assert 0 <= a < self._n
        assert 0 <= b < self._n
        return self.leader(a) == self.leader(b)

    def leader(self, a):
        assert 0 <= a < self._n
        if self.parent_or_size[a] < 0: return a
        self.parent_or_size[a] = self.leader(self.parent_or_size[a])
        return self.parent_or_size[a]

    def size(self, a):
        assert 0 <= a < self._n
        return -self.parent_or_size[self.leader(a)]

    def groups(self):
        leader_buf = [self.leader(i) for i in range(self._n)]
        result = [[] for _ in range(self._n)]
        for i in range(self._n): result[leader_buf[i]].append(i)
        return [r for r in result if r != []]

import random

c = 0
for i in range(2, 5 + 1):
    for j in range(0, i):
        c += 1
        # 辺を貼る
        g = [[] for _ in range(i)]
        d = DSU(i)
        for _ in range(j):
            while 1:
                l = random.randint(0, i - 1)
                r = random.randint(0, i - 1)
                if(l > r):
                    l, r = r, l
                elif l == r:
                    continue
                elif d.same(l, r):
                    continue
                else:
                    d.merge(l, r)
                    g[l].append(r)
                    break
        f = open("small" + str(c) +".txt", mode='w')
        f.write(str(i) + " " + str(j) + "\n")
        for v in range(len(g)):
            for s in g[v]:
                f.write(str(v + 1) + " " + str(s + 1) + "\n")
        f.close()
