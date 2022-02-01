a, b = map(int, input().split())
ans = 0
for i in range(1, a + 1):
    for j in range(0, 32):
        if i == a and j > b:
            break
        if i == j:
            ans += 1

print(ans)