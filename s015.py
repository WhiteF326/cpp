k, s, t = map(int, input().split())

len = [3] * (k + 1)
len[0] = 0
for i in range(2, k + 1):
    len[i] = len[i - 1] * 2 + 3

def rev(k, s, t):
    print(k, s, t)
    if s < 0 or t < 0:
        return ""
    if k == 1:
        return "ABC"[s - 1 : t]
    ret = ""
    if s == 1:
        ret += "A"
    ret += rev(k - 1, max(1, s - 1), min(t - 1, len[k - 1]))
    mid = len[k] // 2 + 1
    if s <= mid and t >= mid:
        ret += "B"
    ret += rev(k - 1, max(s - mid, 1), t - mid)
    if t == len[k]:
        ret += "C"
    return ret

print(rev(k, s, t))