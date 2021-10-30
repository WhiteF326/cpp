import math

n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]

def dim(a, b, c):
    return 0.5 * abs((b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]))

ans = 0
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            if dim(p[i], p[j], p[k]) > 0:
                ans += 1

print(ans)
