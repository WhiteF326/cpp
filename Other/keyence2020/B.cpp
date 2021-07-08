#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  // pair r, l
  vector<pair<int, int>> p(n);
  for(int i = 0; i < n; i++){
    int x, l; cin >> x >> l;
    p[i] = mp(x + l, x - l);
  }
  sort(p.begin(), p.end());

  int ans = 0, rh = p[0].second;

  for(int i = 0; i < n; i++){
    if(rh <= p[i].second){
      ans++;
      rh = p[i].first;
    }
  }
  cout << ans << endl;
}