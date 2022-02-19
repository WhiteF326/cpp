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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> a(1);
  a[0] = 0;
  for(int i = 0; i < n; i++){
    int d; cin >> d;
    for(int &v : a) v = (v + d) % 360;
    a.push_back(0);
  }
  sort(all(a));
  a.push_back(360);

  int ans = 0;
  for(int i = 0; i < n + 1; i++){
    ans = max(ans, a[i + 1] - a[i]);
  }
  cout << ans << endl;
}
