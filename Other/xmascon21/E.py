import math

n = 10**18

ans = [0, math.pi * 2]
current = math.pi * 2
eps = 0.000000000001

for i in range(n):
    x = math.cos(2 * math.pi * math.e * i)
    y = math.sin(2 * math.pi * math.e * i)
    d = math.atan2(y, x)
    if d < 0:
        d = 2 * math.pi + d
    ans.append(d)

    ans = sorted(ans)
    mx = 0
    for j in range(len(ans) - 1):
        mx = max(mx, ans[j + 1] - ans[j])
    
    if current - mx > eps:
        print(i)
    current = mx
