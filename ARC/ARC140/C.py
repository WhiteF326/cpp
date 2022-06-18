from bisect import bisect_left
import itertools


def pe(seq):
    return [abs(seq[i] - seq[i + 1]) for i in range(len(seq) - 1)]

def lis(seq):
    ret = [1 << 60] * (len(seq) + 1)
    ret[0] = -1
    for v in seq:
        idx = bisect_left(ret, v - 1)
        ret[idx] = min(ret[idx], v)
    return ret

n, x = map(int, input().split())

print(([lis(pe(r)) for r in itertools.permutations(range(n)) if r[0] == x]))
print(lis([2, 1, 3, 0, 4]))