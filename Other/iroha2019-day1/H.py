def digitSum(a):
    res = 0
    while a:
        res += a % 10
        a //= 10
    return res

n = 6
ans = 1
while digitSum(n) != digitSum(ans) or n == ans:
    ans += 1
print(ans)
