from sys import argv
from typing import DefaultDict
import numpy as np

if len(argv) == 1:
    seed = 0
else:
    seed = int(argv[1])

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.root = [-1] * n
        self.rank = [0] * n
    
    def find(self, x):
        if self.root[x] < 0:
            return x
        else:
            self.root[x] = self.find(self.root[x])
            return self.root[x]
    
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        elif self.rank[x] > self.rank[y]:
            self.root[x] += self.root[y]
            self.root[y] = x
        else:
            self.root[y] += self.root[x]
            self.root[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1
    
    def same(self, x, y):
        return self.find(x) == self.find(y)
    
    def size(self, x):
        return -self.root[self.find(x)]
    
    def roots(self):
        return [i for i, x in enumerate(self.root) if x < 0]
    
    def group_size(self):
        return len(self.roots())
    
    def group_members(self):
        group_members = DefaultDict(list)
        for member in range(self.n):
            group_members[self.find(member)].append(member)
        return group_members


rng = np.random.default_rng(seed)
n = int(rng.uniform(2, 50000))
n = 50
print(n)

edges = [[int(rng.uniform(0, n)), int(rng.uniform(0, n))] for _ in range(n * 5)]
uf = UnionFind(n)
re_edges = []

for e in edges:
    if uf.same(e[0], e[1]):
        continue
    else:
        uf.unite(e[0], e[1])
        a = int(rng.uniform(0, 1000000001))
        re_edges.append([e[0] + 1, e[1] + 1, a])

u = uf.group_members()
s = [u[elm] for elm in list(u)]
for i in range(len(s) - 1):
    l = s[i][int(rng.uniform(0, len(s[i])))]
    r = s[i + 1][int(rng.uniform(0, len(s[i + 1])))]
    uf.unite(l, r)
    a = int(rng.uniform(0, 1000000001))
    re_edges.append([l + 1, r + 1, a])

for e in re_edges:
    print(" ".join([str(x) for x in e]))