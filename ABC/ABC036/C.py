n = int(input())
a = [int(input()) for _ in range(n)]

b = {v: i for i, v in enumerate(sorted(set(a)))}
print(*[b[v] for v in a])
