n, x, m = map(int, input().split())

ans = 0

for _ in range(n):
    ans += x
    x = (x * x) % m

print(ans)
