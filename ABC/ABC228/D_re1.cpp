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
  int size = 1 << 20;
  vector<ll> cur(size, -1);
  set<ll> used;
  for(int i = 0; i < size; i++){
    used.insert(i);
  }

  int q; cin >> q;
  query(q){
    int t; cin >> t;
    ll x; cin >> x;

    if(t == 1){
      ll h = x % (ll)size;
      auto itr = used.lower_bound(h);
      if(itr == used.end()){
        h = 0;
        itr = used.lower_bound(h);
      }
      h = *itr;

      used.erase(h);
      cur[h] = x;
    }else{
      cout << cur[x % (ll)size] << endl;
    }
  }
}