n = int(input())
assert 1 <= n and n <= 100

a = list(map(int, input().split()))
assert len(a) == n

sxor = 0
for v in a:
    sxor ^= v
assert sxor == 0