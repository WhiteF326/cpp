import functools

s = input()
n = len(s)
ans = 20000000
for c in s:
    # c に圧縮する
    t = s
    act = 0
    while len(set(t)) > 1:
        t = "".join(c if t[i] == c or t[i + 1] == c else t[i] for i in range(len(t) - 1))
        act += 1
    ans = min(ans, act)
print(ans)