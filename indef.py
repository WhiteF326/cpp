from math import gcd


a, b, c = map(int, input().split())
if a < b:
    a, b = b, a

g = gcd(a, b)

if c % g == 0:
    print("No answer")

a /= g
b /= g

while a % b:
    a, b = b, a % b


