import queue
infl = 10**9
n, m = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(lambda e : int(e) - 1, input().split())
    g[a].append(b)
    g[b].append(a)

q = queue.Queue()
q.put(0)
depth = [infl for _ in range(n)]
depth[0] = 0
pathcnt = [0 for _ in range(n)]
pathcnt[0] = 1

while not q.empty():
    dest = q.get()
    for v in g[dest]:
        if depth[v] == infl:
            depth[v] = depth[dest] + 1
            pathcnt[v] = pathcnt[dest]
            q.put(v)
        elif depth[v] == depth[dest] + 1:
            pathcnt[v] += pathcnt[dest]
            pathcnt[v] %= 1000000007

print(pathcnt[n - 1])