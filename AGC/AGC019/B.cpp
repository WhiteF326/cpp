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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string a; cin >> a;
  int n = a.length();

  vector<int> c(26);
  ll ans = 1;
  for(int i = n - 1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      if(j != (a[i] - 'a')) ans += c[j];
    }
    c[a[i] - 'a']++;
  }

  cout << ans << endl;
}