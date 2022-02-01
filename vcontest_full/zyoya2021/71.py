n = int(input())
a = list(map(int, input().split()))
d = []
for i in range(n):
    if i % 2:
        d.insert(0, a[i])
    else:
        d.append(a[i])
if n % 2:
    d.reverse()
print(*d)