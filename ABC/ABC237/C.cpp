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
  
  string s; cin >> s;
  int n = s.length();
  
  int en = 0;
  while(s[n - en - 1] == 'a'){
    en++;
  }

  int st = 0;
  while(s[st] == 'a'){
    st++;
  }

  s = s.substr(st, s.length() - en - st);

  string t = s;
  reverse(all(t));

  cout << ((en >= st && s == t) ? "Yes" : "No") << endl;
}
