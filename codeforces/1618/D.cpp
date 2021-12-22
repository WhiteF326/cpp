#include <bits/stdc++.h>
using namespace std;

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
  int t; cin >> t;
  query(t){
    int n, k; cin >> n >> k;
    vector<ll> def(n);
    aryin(def, n);
    sort(all(def));
    vector<ll> a(0), b(0);
    for(int i = 0; i < n - 2 * k; i++){
      a.push_back(def[i]);
    }
    for(int i = n - 2 * k; i < n; i++){
      b.push_back(def[i]);
    }

    multiset<ll> bx(all(b));

    ll ans = accumulate(all(a), 0LL);
    for(int i = 0; i < k; i++){
      ll v = *bx.begin();
      bx.erase(bx.begin());

      auto itr = bx.upper_bound(v);
      if(itr == bx.end()){
        ans += *bx.rbegin() / v;
        bx.erase(bx.lower_bound(v));
      }else{
        bx.erase(itr);
      }
    }

    cout << ans << endl;
  }
}