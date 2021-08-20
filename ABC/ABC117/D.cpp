#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

ll modv = 998244353;

int main(){
  int n; ll k; cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // 半数以上立っているbitは立てない？
  int harf = n / 2;

  vector<int> popc(41);
  for(int i = 0; i <= 40; i++){
    for(ll v : a){
      popc[i] += (v & (1LL << i) ? 1 : 0);
    }
  }

  ll x = 0;
  for(int i = 40; i >= 0; i--){
    if((1LL << i) > k) continue;
    if(popc[i] <= harf){
      k -= (1LL << i);
      x += (1LL << i);
    }
  }

  ll sum = 0;
  for(ll v : a) sum += x ^ v;
  cout << sum << endl;
}