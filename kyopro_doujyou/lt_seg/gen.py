import random

for id in range(0, 3):
    f = open("./testcases/in/01_test_0" + str(id) + ".txt", "w")
    n = 100000
    q = 100000

    f.write(" ".join(map(str, [n, q])) + "\n")
    for i in range(0, q - 1):
        t = 1
        l = random.randint(1, n)
        r = random.randint(l, n)
        f.write(" ".join(map(str, [t, l, r])) + "\n")
    for i in range(0, 1):
        t = 2
        l = random.randint(1, n)
        r = random.randint(l, n)
        f.write(" ".join(map(str, [t, l, r])) + "\n")
