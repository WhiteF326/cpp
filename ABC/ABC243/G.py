mem = {}

def sqrtint_binary(x):
    l = -1
    r = 3000000001
    while r - 1 > l:
        m = l + (r - l) // 2
        if m * m > x:
            r = m
        else:
            l = m
    return l

def dp(x):
    if x == 1:
        return 1
    if x in mem:
        return mem[x]
    v = 1
    res = 0
    s = sqrtint_binary(x)
    while pow(v, 4) <= x:
        d = min(s + 1, pow(v + 1, 2)) - v * v
        res += d * dp(v * v)
        v += 1
    mem[x] = res
    return res

sqrtint_binary(9 * (10 ** 18))

t = int(input())
while t:
    x = int(input())
    print(dp(x))
    t -= 1