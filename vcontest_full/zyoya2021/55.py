s = input()
if s == "keyence":
    print("YES")
    exit()
n = len(s)

for i in range(n + 1):
    for j in range(n + 1):
        if s[0:i] + s[j:] == "keyence":
            print("YES")
            exit()

print("NO")