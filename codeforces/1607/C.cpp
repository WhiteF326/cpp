#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  // cin.tie(nullptr);
  // ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<ll> v(n);
    aryin(v, n);

    if(n == 1){
      cout << v[0] << endl;
      continue;
    }

    sort(all(v));
    ll ans = LLONG_MIN;
    ll diff = 0;
    bool flg = false;
    for(int i = 0; i < n - 1; i++){
      ans = max(v[i] + diff, ans);
      diff -= v[i] + diff;
    }
    ans = max(v[n - 1] + diff, ans);
    cout << ans << endl;
  }
}