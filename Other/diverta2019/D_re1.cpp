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
  
  ll n; cin >> n;

  ll ans = 0;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      ll m = n / i - 1;
      if(!m) continue;
      if(n / m != n % m) continue;
      ans += m;
    }
  }

  cout << ans << endl;
}
