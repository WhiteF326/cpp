n = int(input())
a = list(map(int, input().split()))


def sign(a: int) -> int:
    return (a > 0) - (a < 0)


# +
ans1 = 0 if a[0] > 0 else 1 - a[0]
prs1 = a[0] if a[0] > 0 else 1
for i in a[1:]:
    if sign(-prs1) == sign(prs1 + i):
        prs1 += i
    else:
        trg1 = -prs1 + sign(-prs1)
        dif1 = max(trg1, i) - min(trg1, i)
        ans1 += dif1
        prs1 = sign(-prs1)

# -
ans2 = 0 if a[0] < 0 else a[0] + 1
prs2 = a[0] if a[0] < 0 else -1
for i in a[1:]:
    if sign(-prs2) == sign(prs2 + i):
        prs2 += i
    else:
        trg2 = -prs2 + sign(-prs2)
        dif2 = max(trg2, i) - min(trg2, i)
        ans2 += dif2
        prs2 = sign(-prs2)

print(min(ans1, ans2))