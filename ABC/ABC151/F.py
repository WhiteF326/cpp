import math

def det(p, q):
    return p[0]*q[1] - p[1]*q[0]


def sub(p, q):
    return (p[0]-q[0], p[1]-q[1])


def get_convex_hull(points):
    n = len(points)
    points.sort()
    size_convex_hull = 0
    ch = []
    for i in range(n):
        while size_convex_hull > 1:
            v_cur = sub(ch[-1], ch[-2])
            v_new = sub(points[i], ch[-2])
            if det(v_cur, v_new) > 0:
                break
            size_convex_hull -= 1
            ch.pop()
        ch.append(points[i])
        size_convex_hull += 1

    t = size_convex_hull
    for i in range(n-2, -1, -1):
        while size_convex_hull > t:
            v_cur = sub(ch[-1], ch[-2])
            v_new = sub(points[i], ch[-2])
            if det(v_cur, v_new) > 0:
                break
            size_convex_hull -= 1
            ch.pop()
        ch.append(points[i])
        size_convex_hull += 1

    return ch[:-1]

n = int(input())
if n == 2:
    x, y = map(int, input().split())
    x2, y2 = map(int, input().split())
    x -= x2
    y -= y2
    print("{:.6f}".format(math.sqrt(x * x + y * y) / 2))
    exit()

points = [list(map(int, input().split())) for _ in range(n)]
hull = get_convex_hull(points)

print(hull)
m = len(hull)

for i in range(m - 2):
    for j in range(1, m - 1):
        for k in range(2, m):
            print(hull[i], hull[j], hull[k])
