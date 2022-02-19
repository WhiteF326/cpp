class modint:
    def __init__(self, x):
        self.x = x % (10 ** 9 + 7)

    def __add__(self, other):
        return modint(self.x + other.x)

    def __sub__(self, other):
        return modint(self.x - other.x)

    def __mul__(self, other):
        return modint(self.x * other.x)

    def __truediv__(self, other):
        return modint(self.x * pow(other.x, 10 ** 9 + 7 - 2, 10 ** 9 + 7))

    def __repr__(self):
        return str(self.x)


s = input()
n = len(s)

dp = [[modint(0) for _ in range(13)] for _ in range(n + 1)]
dp[0][0] = modint(1)

for i in range(n):
    for j in range(13):
        if s[i] == "?":
            for x in range(10):
                dp[i + 1][(j * 10 + x) % 13] += dp[i][j]
        else:
            dp[i + 1][(j * 10 + int(s[i])) % 13] += dp[i][j]

print(dp[n][5])
