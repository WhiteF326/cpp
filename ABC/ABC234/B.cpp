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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i].first >> p[i].second;
  }

  double ans = 0.0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans = max(ans, sqrt(
        pow(abs(p[i].first - p[j].first), 2) + pow(abs(p[i].second - p[j].second), 2)
      ));
    }
  }

  cout << fs(12) << ans << endl;
}