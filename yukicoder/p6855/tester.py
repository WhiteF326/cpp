# Python (not PyPy) speed test

spf = [0 for _ in range(1000001)]
pr = []
for i in range(2, 1000001):
    if spf[i] == 0:
        spf[i] = i
        pr.append(i)
    j = 0
    while j < len(pr) and pr[j] <= spf[i] and i * pr[j] <= 1000000:
        spf[i * pr[j]] = pr[j]
        j += 1

n = int(input())
a = list(map(int, input().split()))
fold = 0
for v in a:
    cnt = 0
    while v > 1:
        v //= spf[v]
        cnt += 1
    fold ^= cnt

print("white" if fold else "black")
