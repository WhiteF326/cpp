n, m = map(int, input().split())
sl = []
for i in range(m):
  sl.append([])
  inputlist = input().split()
  k = int(inputlist[0])
  for j in range(k):
    s = int(inputlist[j + 1])
    sl[i].append(s - 1)

p = list(map(int, input().split()))

ans = 0
for i in range(1 << n):
  swlist = []
  for j in range(n):
    swlist.append(1 if i & (1 << j) else 0)
  light = 0
  for j in range(m):
    res = 0
    for k in sl[j]: res += swlist[k]
    if res % 2 == p[j]: light += 1
  if light == m: ans += 1

print(ans)