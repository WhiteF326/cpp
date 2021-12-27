n = int(input())
l = sorted(int(input()) for _ in range(n))
print(sum(l) - (l[n - 1] // 2))
