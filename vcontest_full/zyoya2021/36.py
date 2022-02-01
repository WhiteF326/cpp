s = input()
t = input()

for i in range(100):
    s = s[1:] + s[0]
    if s == t:
        print("Yes")
        exit()

print("No")