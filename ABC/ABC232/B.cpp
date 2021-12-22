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
  string t; cin >> t;
  vector<int> sl(s.length()), tl(t.length());
  for(int i = 0; i < s.length(); i++){
    sl[i] = s[i] - 'a';
  }
  for(int i = 0; i < t.length(); i++){
    tl[i] = t[i] - 'a';
  }
  bool flg = false;
  for(int i = 0; i < 26; i++){
    bool res = true;
    for(int i = 0; i < s.length(); i++){
      if(sl[i] != tl[i]){
        res = false;
      }
    }
    if(res) flg = true;
    for(int i = 0; i < s.length(); i++){
      sl[i] = (sl[i] + 1) % 26;
    }
  }

  cout << (flg ? "Yes" : "No") << endl;
}