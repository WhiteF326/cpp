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
  
  int n, m; cin >> n >> m;
  vector<int> s(m), c(m);
  for(int i = 0; i < m; i++){
    cin >> s[i] >> c[i];
    s[i]--;
  }
  for(int i = 0; i < 1000; i++){
    string t = to_string(i);
    if(t.length() != n){
      continue;
    }
    bool flg = true;
    for(int j = 0; j < m; j++){
      if(t[s[j]] - '0' != c[j]){
        flg = false;
      }
    }
    if(flg){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}