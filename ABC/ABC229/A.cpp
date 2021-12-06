#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  string s, t; cin >> s >> t;
  bool flg = true;
  if(s[0] == '#'){
    if(s[1] != '#' && t[0] != '#') flg = false;
  }
  if(s[1] == '#'){
    if(s[0] != '#' && t[1] != '#') flg = false;
  }
  if(t[0] == '#'){
    if(s[0] != '#' && t[1] != '#') flg = false;
  }
  if(t[1] == '#'){
    if(s[1] != '#' && t[0] != '#') flg = false;
  }
  cout << (flg ? "Yes" : "No") << endl;
}