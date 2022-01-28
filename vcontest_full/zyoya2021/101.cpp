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


#define mint modint1000000007
vector<mint> f(1000001);

mint C(int n, int k){
  mint a = f[n];
  mint b = f[n - k];
  mint c = f[k];

  return a * (b * c).inv();
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  f[0] = 1;
  for(int i = 1; i <= 1000000; i++) f[i] = f[i - 1] * i;
  
  ll x, y; cin >> x >> y;

  if((x + y) % 3){
    cout << 0 << endl;
  }else{
    ll s = (x + y) / 3;
    if(x > y) swap(x, y);
    if(x < s){
      cout << 0 << endl;
    }else{
      cout << C(s, x - s).val() << endl;
    }
  }
}