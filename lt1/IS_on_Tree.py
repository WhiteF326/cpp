modv = 1000000007

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
in_count = [0 for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
    in_count[a - 1] += 1
    in_count[b - 1] += 1

visited = [False for _ in range(n)]
visited[0] = True

dp = [[0 for _ in range(m + 1)] for _ in range(n)]
for i in range(n):
    if in_count[i] == 1:
        dp[i][m] = 1

def dfs(p):
    visited[p] = True
    for next in graph[p]:
        if visited[next]:
            continue
        dfs(next)
        for i in range(m + 1):
            dp[p][i] += dp[next][i]
    for i in reversed(range(m)):
        dp[p][i] += dp[p][i + 1]

dfs(0)

print(dp)
ans = 0
for v in dp[0]:
    ans = (ans + v) % modv
print(ans)
