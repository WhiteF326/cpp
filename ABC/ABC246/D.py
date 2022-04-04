n = int(input())

f = lambda a, b: a ** 3 + a ** 2 * b + a * b ** 2 + b ** 3
ans = 1 << 63

for a in range(0, 1000001):
    if a % 10000 == 0:
        print(a)
    l = -1
    r = 1000002
    res = 1 << 63
    while r - l > 1:
        m = l + (r - l) // 2
        if f(a, m) < n:
            l = m
        else:
            r = m
            res = min(res, f(a, m))
    ans = min(ans, res)

print(ans)
