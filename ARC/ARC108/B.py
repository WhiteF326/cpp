n = int(input())
s = input()

t = s[0:2]
for i in range(2, n):
    t += s[i]
    if len(t) >= 3:
        if t[-3:] == "fox":
            t = t[:-3]

print(len(t))