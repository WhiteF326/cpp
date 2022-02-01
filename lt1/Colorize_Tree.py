import queue


n, q = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

qu = queue.Queue()
qu.put(0)
visited = [False for _ in range(n)]
visited[0] = True
depth = [1 << 30 for _ in range(n)]
depth[0] = 0

while not qu.empty():
    seeing = qu.get()
    
    for next in graph[seeing]:
        if visited[next]:
            continue
        qu.put(next)
        depth[next] = (depth[seeing] + 1) % 2
        visited[next] = True

for _ in range(q):
    c, d = map(int, input().split())
    res = (depth[c - 1] + depth[d - 1]) % 2
    if res:
        print("Road")
    else:
        print("Town")
