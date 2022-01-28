import functools

n = int(input())
a = list(map(int, input().split()))
rd = functools.reduce(lambda x, y: x ^ y, a)
print(" ".join(str(rd ^ elm) for elm in a))