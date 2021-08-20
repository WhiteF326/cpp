l = [3, 15, 15, 12]
for i in range(16):
  ans = 0
  for j in l:
    ans += j ^ i
  print(i, ans)
