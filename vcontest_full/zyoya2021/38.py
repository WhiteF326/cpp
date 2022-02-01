n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)

q = []
visited = [0 for _ in range(n)]
ans = 0

for i in range(n):
    res = 0
    if visited[i]:
        continue
    q.append(i)
    visited[i] = 1

    while len(q):
        dest = q.pop()
        res += 1
        
        for v in g[dest]:
            if visited[v]:
                continue
            visited[v] = 1
            q.append(v)
    
    ans = max(ans, res)

print(ans)