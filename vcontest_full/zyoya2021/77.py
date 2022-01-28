import bisect

n, m = map(int, input().split())
h = sorted(list(map(int, input().split())))
w = list(map(int, input().split()))

lsum = [h[i + 1] - h[i] for i in range(n - 1)]
rsum = lsum[1::2] + [0]
lsum = [0] + lsum[::2]

for i in range(len(lsum) - 1):
    lsum[i + 1] += lsum[i]
for i in range(len(rsum) - 1, 0, -1):
    rsum[i - 1] += rsum[i]

ans = 2000000000

for v in w:
    x = bisect.bisect(h, v)
    if x % 2:
        x -= 1
    cost = lsum[x // 2] + rsum[x // 2] + abs(h[x] - v)
    ans = min(ans, cost)
print(ans)