n = int(input())
dic = set()
for i in range(n):
    s = input()
    if s in dic:
        print("Yes")
        exit()
    dic.add(s)
print("No")