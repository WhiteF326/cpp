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
  vector<int> a(n);
  aryin(a, n);

  fenwick_tree<int> fw(n);
  ll ans = 0;

  for(int i = 0; i < n; i++){
    ans += i - fw.sum(0, a[i]);
    fw.add(a[i], 1);
  }

  for(int i = 0; i < n; i++){
    cout << ans << " ";
    ans -= a[i];
    ans += n - 1 - a[i];
  }cout << endl;
}
