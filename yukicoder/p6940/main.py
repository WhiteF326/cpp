import itertools

n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))

ans = 0
pa = itertools.permutations(a)
for ls in pa:
    lls = list(ls)
    flg = True
    for i in range(n - 1):
        if abs(lls[i + 1] - lls[i]) > k:
            flg = False
    if flg:
        ans += 1

print(ans)