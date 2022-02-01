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


#define mint modint998244353
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  vector<mint> a(n);
  vector<ll> b(n);

  for(int i = 0; i < n; i++){
    cin >> b[i];
  }
  sort(all(b));

  for(int i = 0; i < n; i++) a[i] = b[i];

  mint ans = 0;
  mint mul = a[n - 1];
  for(int i = n - 1; i >= 0; i--){
    ans += a[i] * mul;
    if(i){
      mul -= a[i];
      mul *= 2;
      mul += a[i - 1] + a[i];
    }
  }

  cout << ans.val() << endl;
}