#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> l(n * 2);
  for(int i = 0; i < n * 2; i++) cin >> l[i];

  sort(l.begin(), l.end());
  int ans = 0;
  for(int i = 0; i < n; i++) ans += l[i * 2];

  cout << ans << endl;
}