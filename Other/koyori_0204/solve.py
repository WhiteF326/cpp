import numpy as np

for y in range(10000000):
    c = (y ** 6) - (3 * (y ** 4)) + (3 * (y ** 2)) - 1
    r = np.roots([
        1, 0, 3 * (y ** 2) - 3 - (y ** 3), 0, 3 * (y ** 4) - 6 * (y ** 2) + 3, 0, c
    ])
    for e in r:
        if np.isreal(e):
            print(e, y)
