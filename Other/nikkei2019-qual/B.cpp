#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string a, b, c; cin >> a >> b >> c;
  int ans = 0;
  for(int i = 0; i < n; i++){
    set<char> s;
    s.insert(a[i]);
    s.insert(b[i]);
    s.insert(c[i]);
    ans += s.size() - 1;
  }
  cout << ans << endl;
}