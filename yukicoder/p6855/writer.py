import sys
import numpy as np

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))

spf = [0 for _ in range(1000001)]
spf[1] = 1
for i in range(2, 1000001):
  if spf[i] : continue;
  for j in range(i, 1000001, i):
    spf[j] = i

grundy = [0 for _ in range(n)]
for i in range(n):
  while a[i] > 1:
    a[i] //= spf[a[i]]
    grundy[i] += 1

nimber = 0
for i in range(n):
  nimber = np.bitwise_xor(nimber, grundy[i])
print("white" if nimber else "black")