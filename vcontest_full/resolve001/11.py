n = int(input())
s = [input() for _ in range(n)]

al = "abcdefghijklmnopqrstuvwxyz"

sc = [[s[i].count(c) for c in al] for i in range(n)]
stx = [" ".join(str(v) for v in sc[i]) for i in range(n)]
m = {}
for e in stx:
    if e in m:
        m[e] += 1
    else:
        m[e] = 1

ans = 0
for e in m:
    ans += m[e] * (m[e] - 1) // 2
print(ans)
