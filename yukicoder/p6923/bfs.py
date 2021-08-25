import queue

infl = 1000000000

n, m, k = map(int, input().split())
a, b = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    x, y = map(int, input().split())
    g[x - 1].append(y - 1)
    g[y - 1].append(x - 1)

q = queue.Queue()
q.put(a - 1)
depth = [infl for _ in range(n)]
depth[a - 1] = 0
visited = [False for _ in range(n)]
visited[a - 1] = True

while not q.empty():
    dest = q.get()
    for v in g[dest]:
        if not visited[v]:
            visited[v] = True
            depth[v] = depth[dest] + 1
            q.put(v)

if k == depth[b - 1]:
    print("shortest")
else:
    print(k - depth[b - 1])