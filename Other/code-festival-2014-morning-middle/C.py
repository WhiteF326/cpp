import fractions
import numpy as np


def mtrx_power(a, n):
    res = np.identity(a.shape[0])
    while n > 0:
        if n & 1:
            res = np.dot(a, res)
        a = np.dot(a, a)
        n >>= 1
    return res


pl, n = input().split()
n = int(n)

# p = fractions.Fraction(pl)
p = float(pl)

mtrx = mtrx_power(np.array([[1-p, p], [p, 1-p]]), n)
print(mtrx[0][1])
