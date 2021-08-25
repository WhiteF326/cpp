l = input()
bl = [c == '1' for c in list(l)]
MODV = 1000000007

# dp[i][smaller] = i桁目まで、未満フラグ:smaller
dp = [[0, 0] for _ in range(len(l) + 1)]
dp[0][0] = 1
for i in range(len(l)):
    for j in range(2):
        if bl[i]:
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][j]) % MODV
        else:
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MODV
        if not(bl[i] == 0 and j == 0):
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 2) % MODV

print((dp[len(l)][0] + dp[len(l)][1]) % MODV)
