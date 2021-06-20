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
  vector<int> w(n);
  for(int i = 0; i < n; i++) cin >> w[i];
  int ac = accumulate(w.begin(), w.end(), 0) - w[0];
  int bc = w[0];
  int ans = INT_MAX;
  for(int i = 0; i < n - 1; i++){
    ans = min(ans, abs(bc - ac));
    ac -= w[i + 1];
    bc += w[i + 1];
  }
  cout << ans << endl;
}