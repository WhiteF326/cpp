# until 317
a, b = input().split()
v = int(a + b)

for i in range(1, 318):
    if v == i ** 2:
        print("Yes")
        exit()

print("No")