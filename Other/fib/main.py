fib = [0 for _ in range(101)]
fib[1] = 1
fib[2] = 1

for i in range(3, 101):
    fib[i] = fib[i - 1] + fib[i - 2]

print(fib[40])