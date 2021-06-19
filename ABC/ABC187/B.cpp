#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<pair<double, double>> pt(n);
  for(int i = 0; i < n; i++){
    double x, y; cin >> x >> y;
    pt[i] = mp(x, y);
  }
  int ans = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(abs((pt[j].second - pt[i].second) / (pt[j].first - pt[i].first)) <= 1) ans++;
    }
  }
  cout << ans << endl;
}