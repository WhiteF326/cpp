n = int(input())
modv = 1000000007
x = pow(10, n, modv)
y = pow(9, n, modv)
z = pow(8, n, modv)
ans = x - 2 * y + z
while ans < 0:
    ans += modv
print(ans)