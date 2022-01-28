import functools

n = int(input())
if n % 2:
    print("Win")
    exit()

a = list(map(int, input().split()))
v = functools.reduce(lambda x, y: x ^ y, a)
if v in a:
    print("Win")
else:
    print("Lose")