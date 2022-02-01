n = int(input())
m = {}
for _ in range(n):
    s = input()
    if s in m:
        m[s] += 1
    else:
        m[s] = 1

print(
    sorted(
        [elm[1], elm[0]] for elm in list(m.items())
    )[len(m) - 1][1]
)
