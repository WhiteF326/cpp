n = int(input())
a = list(map(int, input().split()))

s = a.copy()
for i in range(1, n):
    s[i] += s[i - 1]
v = dict.fromkeys(s)
for e in v:
    v[e] = 0
for d in s:
    v[d] += 1

dif = 0
ans = 0
for i in range(n):
    if dif in v:
        ans += v[dif]
    v[s[i]] -= 1
    dif += a[i]
print(ans)
