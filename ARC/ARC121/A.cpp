#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main()
{
  int n; cin >> n;
  vector<pair<int, int>> p(n);
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
    cin >> y[i];
    p[i] = mp(x[i], y[i]);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int maxv = max(x[n - 1] - x[0], y[n - 1] - y[0]);
  int res = 0;
  if (y[n - 1] - y[0] == maxv){
    if (y[1] == y[0] || y[n - 2] == y[n - 1]){
      cout << maxv << endl;
      return 0;
    }
    res = max(y[n - 1] - y[1], y[n - 2] - y[0]);
    int nx0 = INT_MAX, mx0 = INT_MIN;
    int nx1 = INT_MAX, mx1 = INT_MIN;
    for (int i = 0; i < n; ++i){
      if (p[i].second != y[0]){
        nx0 = min(nx0, p[i].first);
        mx0 = max(mx0, p[i].first);
      }
      if (p[i].second != y[n - 1]){
        nx1 = min(nx1, p[i].first);
        mx1 = max(mx1, p[i].first);
      }
    }
    res = max(res, max(mx0 - nx0, mx1 - nx1));
  }

  if (x[n - 1] - x[0] == maxv){
    if (x[1] == x[0] || x[n - 1] == x[n - 2]){
      cout << maxv << endl;
      return 0;
    }
    res = max(res, max(x[n - 1] - x[1], x[n - 2] - x[0]));
    int ny0 = INT_MAX, my0 = INT_MIN;
    int ny1 = INT_MAX, my1 = INT_MIN;
    for (int i = 0; i < n; ++i){
      if (p[i].first != x[0]){
        ny0 = min(ny0, p[i].second);
        my0 = max(my0, p[i].second);
      }
      if (p[i].first != x[n - 1]){
        ny1 = min(ny1, p[i].second);
        my1 = max(my1, p[i].second);
      }
    }
    res = max(res, max(my0 - ny0, my1 - ny1));
  }
  cout << res << endl;
  return 0;
}