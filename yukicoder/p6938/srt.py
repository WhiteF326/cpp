ans = 0
n = int(input())
for i in range(n + 1):
    if i % 468 == 0 and "4" in list(str(i)):
        ans += 1
print(ans)