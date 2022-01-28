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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) ciｳn >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.length();

  if(n == 1){
    cout << s << endl;
    return 0;
  }

  mint ans = 0;

  vector<mint> sl(n);
  sl[0] = 1, sl[1] = 1;
  for(int i = 2; i < n; i++) sl[i] = sl[i - 1] * 2;

  vector<mint> sls(all(sl));
  for(int i = 1; i < n; i++) sls[i] += sls[i - 1];

  mint fst = 0;
  for(int i = 0; i < n; i++){
    fst += sl[i] * mint(10).pow(n - 1 - i);
  }

  for(int i = 0; i < n; i++){
    ans += fst * (s[i] - '0');
    fst -= sls[i] * mint(10).pow(n - 1 - i);
    if(0 <= n - 2 - i) fst += sls[i] * mint(10).pow(n - 2 - i);
  }
  cout << ans.val() << endl;
}
