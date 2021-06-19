n = int(input())
x = 1
alist = list(map(int,input().split()))
alist = sorted(alist)
mx = 10 ** 18
for i in alist:
  x *= i
  if(x > mx):
    print(-1)
    exit()
print(x)