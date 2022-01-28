#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);
    map<int, int> m;
    for(int i = 0; i < n; i++){
      m[abs(a[i])]++;
    }
    int ans = 0;
    if(m[0]){
      ans += 1;
    }
    for(auto e : m){
      if(!e.first) continue;
      ans += min(2, e.second);
    }

    cout << ans << endl;
  }
}