n = int(input())
a = [int(input()) for _ in range(n)]
g = [[elm - 1] for elm in a]
vis = [0 for _ in range(n)]
depth = [0 for _ in range(n)]

q = [0]
vis[0] = 1
ans = 100000000
while len(q):
    dest = q.pop()
    if dest == 1:
        ans = min(ans, depth[1])
    for v in g[dest]:
        if vis[v]:
            continue
        vis[v] = 1
        q.append(v)
        depth[v] = depth[dest] + 1

if vis[1]:
    print(ans)
else:
    print(-1)