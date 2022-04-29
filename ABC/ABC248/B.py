from math import ceil, log


a, b, k = map(int, input().split())
print(ceil(log(b / a) / log(k)))