#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

ll gcd(ll x, ll y){
  if(y == 0) return x;
  if(x == 0) return y;
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> lowp(1000001, 0);

  lowp[1] = 1;
  for(int i = 2; i <= 1000000; i++){
    if(lowp[i]) continue;
    for(int j = i; j <= 1000000; j += i){
      lowp[j] = i;
    }
  }

  ll allgcd = 0;
  map<int, bool> used;
  bool pairwise = true;

  for(ll v : a){
    allgcd = gcd(v, allgcd);
    ll f = v;
    set<int> prms;
    while(f > 1){
      prms.insert(lowp[f]);
      f /= lowp[f];
    }
    for(auto d : prms){
      if(used[d]) pairwise = false;
      used[d] = true;
    }
  }
  if(pairwise) cout << "pairwise coprime" << endl;
  else if(allgcd == 1) cout << "setwise coprime" << endl;
  else cout << "not coprime" << endl;
}