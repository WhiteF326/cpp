import math

n = int(input())

for i in range(1, 38):
    x = n - 3 ** i
    if x < 0:
        print(-1)
        exit()
    d = int(math.log(x) / math.log(5))
    if x == 5 ** d and d > 0:
        print(i, d)
        exit()

print(-1)