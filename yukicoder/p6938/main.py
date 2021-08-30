s = [ord(i) - 48 for i in list(input())]
n = len(s)

# dp[i][smaller][4flg][mod 468]
dp = [[[[0 for _ in range(468)]
        for _ in range(2)]
       for _ in range(2)]
      for _ in range(n + 1)]

dp[0][0][0][0] = 1
modv = 1000000007

dig = [1 for _ in range(n)]
for i in range(n - 1, 0, -1):
    dig[i - 1] = (dig[i] * 10) % 468

for i in range(n):
    for smaller in [0, 1]:
        for fflg in [0, 1]:
            for modp in range(468):
                if not dp[i][smaller][fflg][modp]:
                    continue
                # choose 0 ~ s[i]
                if not smaller:
                    for d in range(s[i]):
                        nf = d == 4 or fflg
                        np = (modp + dig[i] * d) % 468
                        dp[i + 1][1][nf][np] = \
                            (dp[i + 1][1][nf][np]
                             + dp[i][smaller][fflg][modp]) % modv
                    # d == s[i]
                    nf = s[i] == 4 or fflg
                    np = (modp + dig[i] * s[i]) % 468
                    dp[i + 1][0][nf][np] = \
                        (dp[i + 1][0][nf][np]
                         + dp[i][smaller][fflg][modp]) % modv
                else:
                    for d in range(10):
                        nf = d == 4 or fflg
                        np = (modp + dig[i] * d) % 468
                        dp[i + 1][1][nf][np] = \
                            (dp[i + 1][1][nf][np]
                             + dp[i][smaller][fflg][modp]) % modv

print(sum(dp[n][i][1][0] for i in [0, 1]) % modv)
