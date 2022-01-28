n, q = map(int, input().split())
s = input()

acc = [0 for _ in range(n + 1)]
for i in range(n - 1):
    if s[i:i+2] == "AC":
        acc[i + 2] += 1
for i in range(1, n + 1):
    acc[i] += acc[i - 1]

for i in range(q):
    l, r = map(int, input().split())
    print(acc[r] - acc[l])