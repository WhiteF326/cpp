n = int(input())
c = list(map(int, input().split()))
q = int(input())

t = 0
for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        x, a = query[1], query[2]
        if c[x - 1] >= a:
            c[x - 1] -= a
            t += a
    elif query[0] == 2:
        a = query[1]
        print(min(c[::2]))
        if min(c[::2]) >= a:
            for i in range(n, 2):
                c[i] -= a
                t += a
    elif query[0] == 3:
        a = query[1]
        if min(c) >= a:
            for i in range(n):
                c[i] -= a
                t += a
    print(c, flush=False)

print(t)

