n, x = map(int, input().split())
a = [[] for _ in range(n)]
for i in range(n):
    v = list(map(int, input().split()))
    a[i] = v[1:]

