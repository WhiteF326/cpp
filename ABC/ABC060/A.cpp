#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s, t, u; cin >> s >> t >> u;
  if(s.substr(s.length() - 1, 1) == t.substr(0, 1) && t.substr(t.length() - 1, 1) == u.substr(0, 1)){
    cout << "YES" << endl;
  }else cout << "NO" << endl;
}