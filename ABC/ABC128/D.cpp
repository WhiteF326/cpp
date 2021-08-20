#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  vector<int> v(n);
  int ans = 0;
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int left = 0; left <= k; left++){
    for(int right = 0; right <= k - left; right++){
      int down = k - left - right;
      vector<int> dq;
      int res = 0;
      for(int i = 0; i < left; i++){
        res += v[i];
        if(v[i] < 0) dq.push_back(v[i]);
      }
      for(int i = 0; i < right; i++){
        res += v[n - 1 - i];
        if(v[n - 1 - i] < 0) dq.push_back(v[n - 1 - i]);
      }
      sort(all(dq));
      for(int i = 0; i < min(down, (int)dq.size()); i++){
        res -= dq[i];
      }
      ans = max(ans, res);
    }
  }
  cout << ans << endl;
}