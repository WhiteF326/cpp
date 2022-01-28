import math

n = int(input())
x0, y0 = map(int, input().split())
xe, ye = map(int, input().split())

xc = (x0 + xe) / 2
yc = (y0 + ye) / 2
xv0 = x0 - xc
yv0 = y0 - yc

a = 360 * math.pi / 180 / n
xv1 = xv0 * math.cos(a) - yv0 * math.sin(a)
yv1 = xv0 * math.sin(a) + yv0 * math.cos(a)

print(xv1 + xc, yv1 + yc)
