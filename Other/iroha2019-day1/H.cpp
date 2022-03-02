#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll n; cin >> n;
  string t = to_string(n);

  // if n < 10, then 1(n-1)
  if(n < 10){
    cout << 1 << (n - 1) << endl;
    return 0;
  }

  int m = t.length();
  // if all 9, then 18999……
  bool allNine = true;
  for(int i = 0; i < m; i++){
    if(t[i] != '9') allNine = false;
  }
  if(allNine){
    cout << 18;
    for(int i = 0; i < m - 1; i++){
      cout << 9;
    }
    cout << endl;
    return 0;
  }

  // if all 9 except first digit, then x8999……
  bool almostNine = true;
  for(int i = 1; i < m; i++){
    if(t[i] != '9') almostNine = false;
  }
  if(almostNine){
    cout << (char)(t[0] + 1);
    cout << 8;
    for(int i = 0; i < m - 2; i++){
      cout << 9;
    }
    cout << endl;
    return 0;
  }

  int s = 0;
  while(n){
    s += n % 10LL;
    n /= 10LL;
  }

  string ans = "";
  while(s){
    ans = (char)('0' + min(s, 9)) + ans;
    s -= min(s, 9);
  }
  cout << ans << endl;
}
