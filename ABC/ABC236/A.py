s = input()

a, b = map(int, input().split())
s[a - 1], s[b - 1] = s[b - 1], s[a - 1]
print(s)