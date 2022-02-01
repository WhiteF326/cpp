#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];

  ll l; cin >> l;

  // 2^i 日後、どこにいるか？
  vector<vector<ll>> dbl(31, vector<ll>(n));
  for(int i = 0; i < n; i++){
    if(x[i] + l >= x[n - 1]){
      dbl[0][i] = n;
    }else{
      dbl[0][i] = upper_bound(all(x), x[i] + l) - x.begin() - 1;
    }
  }
  for(int k = 0; k < 30; k++){
    for(int i = 0; i < n; i++){
      if(dbl[k][i] == n){
        dbl[k + 1][i] = n;
      }else{
        dbl[k + 1][i] = dbl[k][dbl[k][i]];
      }
    }
  }
  
  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);
    a--, b--;

    ll ans = 0;
    while(a < b){
      for(int i = 1; i < 31; i++){
        if(dbl[i][a] > b){
          a = dbl[i - 1][a];
          ans += 1 << (i - 1);
          break;
        }
      }
    }

    cout << ans << endl;
  }
}