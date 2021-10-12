n, m = map(int, input().split())
a = list(map(int, input().split()))

dp = [[[0 for _ in range(n + 1)] for _ in range(n + 1)] for _ in range(m + 1)]
dp[0][a.count(4)][a.count(6)] = 1

for i in range(m):
    for f in range(n + 1):
        for s in range(n + 1):
            if dp[i][f][s]:
                if f:
                    dp[i + 1][f - 1][s] += f * dp[i][f][s]
                if s:
                    dp[i + 1][f][s - 1] += s * dp[i][f][s]
                if n - i - f - s:
                    dp[i + 1][f][s] += (n - i - f - s) * dp[i][f][s]

for i in range(m):
    cnt = 0
    est = 0
    for f in range(1, n + 1):
        for s in range(1, n + 1):
            cnt += dp[i + 1][f][s]
            est += dp[i + 1][f][s]
    for f in range(n + 1):
        est += dp[i + 1][f][0]
    for s in range(n + 1):
        est += dp[i + 1][0][s]
    est -= dp[i + 1][0][0]

    print("{:.6f}".format(cnt / est))
