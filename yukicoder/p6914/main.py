n = int(input())
a = list(map(int, input().split()))

ans = 0

while(len(a)):
    dp = [[[0, 0, 0] for _ in range(2048)] for _ in range(n + 1)]
    dp[0][0][0] = 1
    for i in range(1, n + 1):
        for j in range(2048):
            if dp[i - 1][j][0]:
                # use a[i - 1]
                dp[i][j ^ a[i - 1]][0] += dp[i - 1][j][0]
                dp[i][j ^ a[i - 1]][1] = j
                dp[i][j ^ a[i - 1]][2] = 1
                # don't use a[i - 1]
                dp[i][j][0] += dp[i - 1][j][0]
                dp[i][j][1] = j
                dp[i][j][2] = 0
        if dp[i][0][0]:
            # restore
            ans += 1
            ptr = i
            xr = 0
            route = []
            while i > 0:
                if dp[i][xr][2]:
                    route.append(a[i - 1])
                xr = dp[i][xr][1]
                i -= 1
            break
    for v in route:
        a.remove(v)