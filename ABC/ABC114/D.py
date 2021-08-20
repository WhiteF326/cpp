import math

sqrt = math.sqrt


def erpm(val: int):
    ret = {}
    for i in range(2, val):
        while val % i == 0:
            val //= i
            if i in ret:
                ret[i] += 1
            else:
                ret[i] = 1
    if val > 1:
        if val in ret:
            ret[val] += 1
        else:
            ret[val] = 1
    return ret


n = int(input())
prs = {}
for i in range(1, n + 1):
    ep = erpm(i)
    for k, v in ep.items():
        if k in prs:
            prs[k] += v
        else:
            prs[k] = v

# {75} {3, 25} {5, 15} {3, 5, 5}
ans = 0
elm = list(prs.keys())
for i in elm:
    if prs[i] >= 74:
        ans += 1

for i in elm:
    for j in elm:
        if prs[i] >= 2 and prs[j] >= 24 and i != j:
            ans += 1

for i in elm:
    for j in elm:
        if prs[i] >= 4 and prs[j] >= 14 and i != j:
            ans += 1

for i in elm:
    for j in range(len(elm)):
        for k in range(j + 1, len(elm)):
            if(prs[i] >= 2
               and prs[elm[j]] >= 4
               and prs[elm[k]] >= 4
               and i != elm[j]
               and i != elm[k]):
                ans += 1

print(ans)
