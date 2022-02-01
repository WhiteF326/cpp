line = input().split()
n = int(line[0])
s = line[1]

ans = 0

for i in range(n - 1):
    m = {}
    m[s[i]] = 1
    for j in range(i + 1, n):
        if s[j] in m:
            m[s[j]] += 1
        else:
            m[s[j]] = 1
        if "A" in m:
            a = m["A"]
        else:
            a = 0
        if "T" in m:
            t = m["T"]
        else:
            t = 0
        if "C" in m:
            c = m["C"]
        else:
            c = 0
        if "G" in m:
            g = m["G"]
        else:
            g = 0

        if a == t and c == g:
            ans += 1

print(ans)