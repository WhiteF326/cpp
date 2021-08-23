import sys
sys.setrecursionlimit(1 << 25)

n = int(input())
e = [[] for _ in range(n)]
ans = [0 for _ in range(n)]

for i in range(0, n - 1):
    a, b = map(int, input().split())
    e[a - 1].append([b - 1, i])
    e[b - 1].append([a - 1, i])


def dfs(cur: int, par=-1, col=0):
    u = [col]
    color = 1
    for t in e[cur]:
        if t[0] != par:
            while color in u:
                color += 1
            ans[t[1]] = color
            dfs(t[0], cur, color)
            color += 1


dfs(0)

print(max(len(row) for row in e))
print("\n".join(map(str, ans[0:n - 1])))
