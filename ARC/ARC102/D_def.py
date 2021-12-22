class Edge:
    f = 0
    t = 0
    c = 0
    def __init__(self, f, t, c):
        self.f = f
        self.t = t
        self.c = c
    def __str__(self):
        return str(self.f) + " " + str(self.t) + " " + str(self.c)


l = int(input())

v = 1
edges = []

n = 2
cost = 1
while n <= l:
    edges.append(Edge(v, v + 1, 0))
    edges.append(Edge(v, v + 1, cost))
    cost <<= 1
    v += 1
    n <<= 1

sink = v

n >>= 1
nx = n
l -= n

while l > 0:
    if l >= n:
        edges.append(Edge(v, sink, nx))
        l -= n
        nx += n
    n >>= 1
    v -= 1

print(sink, len(edges))

for e in edges:
    print(e)
