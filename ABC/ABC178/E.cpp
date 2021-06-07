#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<pair<int, int>> points(n, pair<int, int>());
  int x_last = 0;

  // 旋回したものも必要

  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    points[i] = mp(x, y);
    x_last = max(x_last, x);
  }

  int ans = 0;
  vector<int> mh(n, 0);
  for(int i = 0; i < n; i++){
    mh[i] = points[i].first + points[i].second;
  }
  sort(mh.begin(), mh.end());
  ans = mh[n - 1] - mh[0];

  // (y, x_last - x)
  for(int i = 0; i < n; i++){
    mh[i] = (x_last - points[i].first) + points[i].second;
  }
  sort(mh.begin(), mh.end());
  ans = max(ans, mh[n - 1] - mh[0]);
  cout << ans << endl;
}
