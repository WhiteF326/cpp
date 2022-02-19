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


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  mint ans = 0;

  auto nSum = [](mint x){
    return x * (x + 1) / 2;
  };

  if(n < 10){
    cout << nSum(mint(n)).val() << endl;
    return 0;
  }

  ll left = 1;
  ll right = 10;
  for(int i = 1; i < 19; i++){
    if(left > n){
      break;
    }
    ans += nSum(min(right - 1, n) - left + 1);

    left *= 10LL;
    right *= 10LL;
  }

  cout << ans.val() << endl;
}
