#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  int w; cin >> w;
  for(int i = 0; i < s.length(); i += w) cout << s[i];
  cout << endl;
}