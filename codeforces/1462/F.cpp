#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0; i < n; i++){
      int a, b; cin >> a >> b;
      v[i] = {a, b};
      l[i] = a;
      r[i] = b;
    }
    sort(all(l));
    sort(all(r));

    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
      int res = upper_bound(all(l), v[i].second) - l.begin();
      res -= lower_bound(all(r), v[i].first) - r.begin();
      ans = min(ans, n - res);
    }

    cout << ans << endl;
  }
}