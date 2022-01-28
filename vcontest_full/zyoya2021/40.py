n, a, b = map(int, input().split())

if a > b:
    print(0)
elif b - a > 0 and n == 1:
    print(0)
else:
    print(b * (n - 1) + a - a * (n - 1) - b + 1)