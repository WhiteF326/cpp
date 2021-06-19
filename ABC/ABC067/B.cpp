#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  vector<int> l(n);
  for(int i = 0; i < n; i++) cin >> l[i];
  sort(l.begin(), l.end(), greater<int>());

  int ans = 0;
  for(int i = 0; i < k; i++) ans += l[i];
  cout << ans << endl;
}