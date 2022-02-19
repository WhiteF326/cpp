import math

n = int(input())
x = [0] * n
y = [0] * n
for i in range(n):
    x[i], y[i] = map(int, input().split())

# choose i, j such that minimize sqrt((x[i] - x[j])**2 + (y[i] - y[j])**2)
# O(n^2)
ans = float('inf')
for i in range(n - 1):
    for j in range(i + 1, n):
        ans = min(ans, (x[i] - x[j])**2 + (y[i] - y[j])**2)

print(math.sqrt(ans))
