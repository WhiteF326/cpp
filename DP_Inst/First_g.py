# n 個の品物(items に価値を格納) から任意の個数選ぶ
# 価値の総和が k を超えないうちで最高になるような組み合わせにおける、価値の総和を答える


n, k = map(int, input().split())
items = list(map(int, input().split()))

LIMIT = 100000

dp = [[False for _ in range(LIMIT + 1)] for _ in range(n + 1)]
dp[0][0] = True

for i in range(1, n + 1):
    for j in range(items[i - 1], LIMIT + 1):
        if not dp[i - 1][j - items[i - 1]]:
            continue
        # i 番目の品物を選ぶ場合
        dp[i][j] = True
        # 選ばない場合
        dp[i][j - items[i - 1]] = True

ans = max([(i if dp[n][i] else 0) for i in range(k + 1)])
print(ans)
