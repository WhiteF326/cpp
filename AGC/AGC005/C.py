n = int(input())
a = list(reversed(sorted(list(map(int, input().split())))))

vm = a[0]
vn = a[n - 1]
if vm > n - 1:
    print("Impossible")
    exit()
if vn < (vm + 1) // 2:
    print("Impossible")
    exit()

m = {}
for e in a:
    if e in m:
        m[e] += 1
    else:
        m[e] = 1

if vm % 2 == 0 and m[vn] != 1:
    print("Impossible")
    exit()
if vm % 2 == 1 and m[vn] != 2:
    print("Impossible")
    exit()

for v in range(vn + 1, vm + 1):
    if not v in m:
        print("Impossible")
        exit()
    if m[v] < 2:
        print("Impossible")
        exit()

print("Possible")
