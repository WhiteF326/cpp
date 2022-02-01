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
  string s, t; cin >> s >> t;
  
  vector<int> a, b;
  for(int i = 0; i < n; i++){
    if(s[i] == '0') a.push_back(i);
    if(t[i] == '0') b.push_back(i);
  }

  if(a.size() != b.size()){
    cout << -1 << endl;
  }else{
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
      if(a[i] != b[i]) ans++;
    }
    cout << ans << endl;
  }
}