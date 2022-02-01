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
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  string s; cin >> s;

  map<pair<string, string>, ll> cnt;
  for(int bit = 0; bit < (1 << n); bit++){
    string a = "";
    string b = "";
    for(int i = 0; i < n; i++){
      if(bit & (1 << i)) a = s[i] + a;
      else b = s[i] + b;
    }
    cnt[{b, a}]++;
  }

  ll ans = 0;
  for(int bit = 0; bit < (1 << n); bit++){
    string a = "";
    string b = "";
    for(int i = 0; i < n; i++){
      if(bit & (1 << i)) a += s[i + n];
      else b += s[i + n];
    }
    ans += cnt[{a, b}];
  }

  cout << ans << endl;
}
