import math
import sys

sys.setrecursionlimit(1 << 20)

a, n = map(int, input().split())
visited = [False for _ in range(10000001)]
ans = 99999999

def dfs(cur, depth):
    global ans
    if visited[cur]:
        return
    visited[cur] = True
    if cur == n:
        ans = min(ans, depth)
        return
    if int(math.log10(cur)) > int(math.log10(n)):
        return
    dfs(cur * a, depth + 1)
    if cur % 10 == 0:
        return
    s = (10 ** int(math.floor(math.log10(cur)))) * (cur % 10) + cur // 10
    dfs(s, depth + 1)

dfs(1, 0)

if visited[n]:
    print(ans)
else:
    print(-1)