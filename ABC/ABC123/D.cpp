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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int x, y, z, k; cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  aryin(a, x); aryin(b, y); aryin(c, z);
  sort(all(c), greater<ll>());

  if(x * y <= k){
    vector<ll> anslist(0);
    for(int i = 0; i < x; i++){
      for(int j = 0; j < y; j++){
        for(int k = 0; k < z; k++){
          anslist.push_back(a[i] + b[j] + c[k]);
        }
      }
    }
    sort(all(anslist), greater<ll>());
    for(int i = 0; i < k; i++){
      cout << anslist[i] << endl;
    }
    return 0;
  }

  vector<ll> muls(x * y);
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      muls[i * y + j] = a[i] + b[j];
    }
  }
  sort(all(muls), greater<ll>());

  vector<ll> anslist(k, 0);
  for(int i = 0; i < k; i++){
    anslist[i] = c[0] + muls[i];
  }

  sort(all(anslist), greater<ll>());
  ll m = anslist[k - 1];

  reverse(all(muls));

  // m - c[i] より大きい muls の要素だけを調べる
  for(int i = 1; i < z; i++){
    ll ls = m - c[i];
    auto itr = lower_bound(all(muls), ls);
    for(; itr != muls.end(); itr++){
      anslist.push_back(*itr + c[i]);
    }
  }
  sort(all(anslist), greater<ll>());
  for(int i = 0; i < k; i++){
    cout << anslist[i] << endl;
  }
}