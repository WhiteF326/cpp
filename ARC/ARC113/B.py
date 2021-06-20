x = list(map(int,input().split()))
a, b, c = x
v = pow(b, c, 4)
if v == 0: v = 4
print(pow(a, v) % 10)