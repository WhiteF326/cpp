n = int(input())
ert = [True for _ in range(10001)]
ert[0] = False
ert[1] = False
for i in range(2, 101):
    if not ert[i]:
        continue
    for j in range(i + i, 10001, i):
        ert[j] = False

print(sum(ert[0:n]))