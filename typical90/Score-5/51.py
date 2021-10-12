from bisect import bisect

n, k, p = map(int, input().split())
a = list(map(int, input().split()))

e = a[0::2]
o = a[1::2]

esum = [[] for _ in range(len(e) + 1)]
osum = [[] for _ in range(len(o) + 1)]

for i in range(1 << len(e)):
    sum = 0
    pc = 0
    for j in range(len(e)):
        if i & 1 << j:
            sum += e[j]
            pc += 1
    esum[pc].append(sum)

for i in range(1 << len(o)):
    sum = 0
    pc = 0
    for j in range(len(o)):
        if i & 1 << j:
            sum += o[j]
            pc += 1
    osum[pc].append(sum)

osum = [sorted(osl) for osl in osum]
ans = 0

for l in range(len(e)):
    r = k - l
    for v in esum[l]:
        # print(osum[r], p - v)
        ans += bisect(osum[r], p - v)

print(ans)