n, m = map(int, input().split())
d = 1
c = 0
while n > m * d:
    d *= 3
    c += 1
print(c)