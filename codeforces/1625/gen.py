import random

print(1)
n = random.randint(2, 150000)
print(n)
a = [random.randint(1, 150000) for _ in range(n)]
print(*a)