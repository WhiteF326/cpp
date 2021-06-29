#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k; vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  sort(h.begin(), h.end());
  int ans = INT_MAX;
  for(int i = 0; i < n - k + 1; i++){
    ans = min(ans, h[i + k - 1] - h[i]);
  }
  cout << ans << endl;
}