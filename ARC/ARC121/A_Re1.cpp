#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<pair<int, int>> p(n);
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
    cin >> y[i];
    p[i] = {x[i], y[i]};
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int maxv = max(x[n - 1] - x[0], y[n - 1] - y[0]);
  int res = 0;
  if (y[n - 1] - y[0] >= x[n - 1] - x[0]){
    if (y[1] == y[0] || y[n - 2] == y[n - 1]){
      cout << max(x[n - 1] - x[0], y[n - 1] - y[0]) << endl;
      return 0;
    }
    res = max(y[n - 1] - y[1], y[n - 2] - y[0]);
    int nxl = INT_MAX, mxl = INT_MIN;
    int nxr = INT_MAX, mxr = INT_MIN;
    for (int i = 0; i < n; ++i){
      if (p[i].second != y[0]){
        nxl = min(nxl, p[i].first);
        mxl = max(mxl, p[i].first);
      }
      if (p[i].second != y[n - 1]){
        nxr = min(nxr, p[i].first);
        mxr = max(mxr, p[i].first);
      }
    }
    res = max(res, max(mxl - nxl, mxr - nxr));
  }

  if (x[n - 1] - x[0] >= y[n - 1] - y[0]){
    if (x[1] == x[0] || x[n - 1] == x[n - 2]){
      cout << max(x[n - 1] - x[0], y[n - 1] - y[0]) << endl;
      return 0;
    }
    res = max(res, max(x[n - 1] - x[1], x[n - 2] - x[0]));
    int nyl = INT_MAX, myl = INT_MIN;
    int nyr = INT_MAX, myr = INT_MIN;
    for (int i = 0; i < n; ++i){
      if (p[i].first != x[0]){
        nyl = min(nyl, p[i].second);
        myl = max(myl, p[i].second);
      }
      if (p[i].first != x[n - 1]){
        nyr = min(nyr, p[i].second);
        myr = max(myr, p[i].second);
      }
    }
    res = max(res, max(myl - nyl, myr - nyr));
  }
  cout << res << endl;
  return 0;
}