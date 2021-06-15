#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string s, t; cin >> s >> t;
  string ans = "";
  for(int i = 0; i < n; i++){
    ans += s[i];
    ans += t[i];
  }
  cout << ans << endl;
}