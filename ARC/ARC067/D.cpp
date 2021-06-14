#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; ll a, b; cin >> n >> a >> b;
  vector<ll> pt(n);
  for(int i = 0; i < n; i++) cin >> pt[i];
  // 東へ貪欲
  ll ans = 0;
  for(int i = 0; i < n - 1; i++){
    ans += min(b, a * (pt[i + 1] - pt[i]));
  }
  cout << ans << endl;
}
