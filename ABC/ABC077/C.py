N = int(input())
ABC = [list(map(int, input().split())) for _ in range(3)]
for i in range(3):
    ABC[i].sort()

dp = [[1] * N] + [[0] * N for _ in range(2)]
for i in range(2):
    tmp = 0
    k = 0
    for j in range(N):
        while k < N and ABC[i + 1][j] > ABC[i][k]:
            tmp += dp[i][k]
            k += 1
        dp[i + 1][j] = tmp
print(sum(dp[2]))

print(dp)