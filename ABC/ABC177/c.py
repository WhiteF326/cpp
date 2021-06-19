modv = 1000000007

n = int(input())
alist = list(map(int,input().split()))
acs = [0]
for i in range(n):
  acs.append(acs[i] + alist[i])

ans = 0
for i in range(n - 1):
  ans += (alist[i] * (acs[n] - acs[i + 1])) % modv;

print(ans % modv)