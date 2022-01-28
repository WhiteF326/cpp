n, t = map(int, input().split())
tl = list(map(int, input().split()))
tl.append(100000000000)

ans = sum([min(tl[i] + t, tl[i + 1]) - tl[i] for i in range(n)])
print(ans)