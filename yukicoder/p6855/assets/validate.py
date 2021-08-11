n = int(input())
assert 1 <= n and n <= 1000000
alist = list(map(int, input().split()))
assert len(alist) == n
for i in range(n):
  a = alist[i]
  assert 1 <= a and a <= 1000000