#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];
  sort(p.begin(), p.end());
  int ans = 0;
  for(int i = 0; i < k; i++){
    ans += p[i];
  }
  cout << ans << endl;
}