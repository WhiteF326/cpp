import sys


def isAdjacent(x1, y1, x2, y2):
    if x1 == x2 and abs(y1 - y2) == 1:
        return True
    if y1 == y2 and abs(x1 - x2) == 1:
        return True
    return False

n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]
m = int(input())
h = [list(map(int, input().split())) for _ in range(m)]

a = [0] * m
step = "urld"
up_step = "URLD"
way = [
    [-1, 0],
    [0, 1],
    [0, -1],
    [1, 0]
]

for _ in range(300):
    for i in range(m):
        if a[i] == 4:
            print(".", end="")
        else:
            dx = h[i][0] + way[a[i]][0]
            dy = h[i][1] + way[a[i]][1]
            # print("##", dx, dy)
            flg = False
            for j in range(m):
                if h[j][0] == dx and h[j][1] == dy:
                    print(".", end="")
                    a[i] += 1
                    flg = True
                    break
            if not flg:
                for j in range(n):
                    # print("#", p[j][0], p[j][1])
                    if isAdjacent(p[j][0], p[j][1], dx, dy) or (p[j][0] == dx and p[j][1] == dy):
                        print(".", end="")
                        flg = True
                        break
            if not flg:
                print(step[a[i]], end="")
                # print(step[a[i]])
                a[i] += 1
    print("")
    sys.stdout.flush()
    pt = input().split()
    for i in range(n):
        for c in list(pt[i]):
            for j in list(up_step):
                if c == j:
                    p[i][0] += way[up_step.index(j)][0]
                    p[i][1] += way[up_step.index(j)][1]
                    break
