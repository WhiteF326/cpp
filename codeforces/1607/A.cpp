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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    string s; cin >> s;
    string v; cin >> v;
    int str = find(all(s), v[0]) - s.begin();
    int ans = 0;
    for(char c : v){
      int nxt = find(all(s), c) - s.begin();
      ans += abs(nxt - str);
      str = nxt;
    }
    cout << ans << endl;
  }
}