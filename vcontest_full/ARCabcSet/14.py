n = int(input())
s = input()

if len(s) <= 2:
    print(len(s))
    exit()

t = s[0:2]
for i in range(2, n):
    t += s[i:i+1]
    if t[-3:] == "fox":
        t = t[:-3]
print(len(t))
# print(t)