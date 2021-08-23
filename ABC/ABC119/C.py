import sys
sys.setrecursionlimit(1 << 25)

n, a, b, c = map(int, input().split())
l = [int(input()) for _ in range(n)]
trg = [a, b, c]

work = [-1 for _ in range(n)]


def dfs(point) -> int:
    if point == n:
        len = [0 for _ in range(3)]
        ch = [0 for _ in range(3)]
        for i in range(n):
            if work[i]:
                len[work[i] - 1] += l[i]
                ch[work[i] - 1] += 1
        if 0 in ch:
            return 1e9
        diff = sum(abs(trg[i] - len[i]) for i in range(3))
        chl = sum(n - 1 for n in ch)
        return diff + chl * 10
    pass

    ret = 1e9

    for i in range(4):
        work[point] = i
        ret = min(dfs(point + 1), ret)
    return ret


print(int(dfs(0)))
