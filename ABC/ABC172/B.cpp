#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s, t; cin >> s >> t;
  int ans = 0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] != t[i]) ans++;
  }
  cout << ans << endl;
}