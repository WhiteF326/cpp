n, k = map(int, input().split())
v: list[int] = list(map(int, input().split()))
ans = 0
for l in range(min(k + 1, n)):
    for r in range(0, min(k, n) - l + 1):
        down: int = k - l - r
        dq: list[int] = []
        res: int = 0
        for i in range(l):
            res += v[i]
            if v[i] < 0:
                dq.append(v[i])
        for i in range(1, r + 1):
            res += v[-i]
            if v[-i] < 0:
                dq.append(v[-i])
        dq = sorted(dq)
        for i in range(min(down, len(dq))):
            res -= dq[i]
        ans = max(ans, res)
print(ans)
