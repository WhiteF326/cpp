n = int(input())
border = [1, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 4801]
res = [0 for _ in range(9)]
a = list(map(int, input().split()))
for v in a:
    for j in range(10):
        if v < border[j]:
            res[j - 1] += 1
            break

ans = sum(min(1, res[i]) for i in range(8))
print(max(ans, 1), ans + res[8])