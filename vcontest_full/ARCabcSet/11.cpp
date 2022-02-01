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
  
  ll n, k; cin >> n >> k;
  k = abs(k);
  ll ans = 0;
  
  auto f = [&](int x){
    if(x >= n + 2){
      return n - (x - n - 1);
    }else{
      return (ll)x - 1;
    }
  };

  for(int i = k + 2; i <= 2 * n; i++){
    ans += f(i) * f(i - k);
  }
  cout << ans << endl;
}