a, b, c = map(int, input().split())
res = pow(b, c, 4)
if res == 0:
    res = 4
print(pow(a, res, 10))