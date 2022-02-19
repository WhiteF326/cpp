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


ld eps = 10e-7;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> a(n);
  aryin(a, n);

  auto fq = [&](ld x){
    ld res = 0;
    for(ll v : a){
      res += (x + (ld)v) - min((ld)v, 2 * x);
    }
    return res / n;
  };

  ld l = 0, r = pow(10, 12);

  while(r - l > eps){
    ld ml = (2 * l + r) / 3.0;
    ld mr = (l + 2 * r) / 3.0;

    if(fq(ml) > fq(mr)){
      l = ml;
    }else{
      r = mr;
    }
  }

  cout << fs(12) << fq(r) << endl;
}
