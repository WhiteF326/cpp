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
  
  int n, k; cin >> n >> k;
  ll ans = 0;

  ll m = 0;
  for(int i = 1; i <= n; i++) if(i % k == 0) m++;
  ans = m * m * m;

  if(k % 2 == 0){
    ll c = 0;
    for(int i = 1; i <= n; i++) if(i % k == k / 2) c++;
    ans += c * c * c;
  }

  cout << ans << endl;
}