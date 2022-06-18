k = int(input())

n = [0] * 50
for _ in range(k):
    n[0] += 50
    for i in range(1, 50):
        n[i] += 1

print(50 * (10 ** 16))
print(n)