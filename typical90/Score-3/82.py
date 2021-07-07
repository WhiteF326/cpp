# int main(){
#   ll l, r; cin >> l >> r;
#   // 桁ごとに計算する
#   for(int i = 0; i < 20; i++){
#     ll start = modpow(10, i, 0);
#     ll end = modpow(10, i + 1, 0) - 1;
#   }
# }
modv = 1000000007

def ssum(i):
  return ((i * (i + 1)) * pow(2, -1, modv)) % modv

l, r = map(int, input().split())
ans = 0

for i in range(20):
  start = pow(10, i)
  end = pow(10, i + 1) - 1
  if end < l:
    continue
  if start > r:
    break

  start = (max(start, l) - 1) % modv
  end = min(end, r) % modv
  ans += ((i + 1) * ((ssum(end) - ssum(start)) % modv)) % modv
  ans = ans % modv

print(int(ans))