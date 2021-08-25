while 1:
    l = list(map(int, input().split()))
    for i in range(1, (1 << len(l)) - 1):
        bit = []
        for j in range(len(l)):
            if i & (1 << j):
                bit.append(j)
        ans = 0
        for j in bit:
            ans ^= l[j]
        if ans == 0:
            print("caution")
            print(bit)
            exit()