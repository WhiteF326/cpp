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

n = 1
while (1 << n) <= l:
    edges.append(Edge(n, n + 1, 0))
    edges.append(Edge(n, n + 1, 1 << (n - 1)))
    n += 1

v = sink = n
n = 1 << (n - 1)

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
