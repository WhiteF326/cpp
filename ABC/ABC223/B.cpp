#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  string s; cin >> s;
  vector<string> sl;
  for(int i = 0; i < s.length(); i++){
    string t = s.substr(1) + s[0];
    sl.push_back(t);
    s = t;
  }
  sort(all(sl));
  cout << sl[0] << endl;
  cout << sl[s.length() - 1] << endl;
}