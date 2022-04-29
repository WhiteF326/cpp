def comb(n, k):
    ret = 1
    for i in range(k):
        ret *= n - i
        ret /= k - i
    return ret

n, d = map(int, input().split())
x, y = map(int, input().split())
x = abs(x)
y = abs(y)

if x % d or y % d:
    print(0)
    exit()

x //= d
y //= d

if (n - (x + y)) & 1:
    print(0)
    exit()

ans = 0
t = (n - (x + y)) // 2

i = (x + y + n) // 2
j = (x - y + n) // 2

ans = comb(n, i) / pow(2, n) * comb(n, j) / pow(2, n)

print("{:.11f}".format(ans))
