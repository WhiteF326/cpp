#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

ll modv = 998244353;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  auto sign = [](ll a)->ll{return (a > 0) - (a < 0);};

  // +
  ll ans1 = 0;
  ll psc = a[0];
  for(int i = 1; i < n; i++){
    if(abs(a[i]) > abs(psc) && sign(a[i]) != sign(psc)){
      psc += a[i];
    }else{
      ll trg = -psc + sign(-psc);
      ll dif = max(a[i], trg) - min(a[i], trg);
      ans1 += dif;
      psc += trg;
    }
  }

  // -
  ll ans2 = 0;
  ll psc = a[0];
  for(int i = 1; i < n; i++){
    if(abs(a[i]) > abs(psc) && sign(a[i]) != sign(psc)){
      psc += a[i];
    }else{
      ll trg = -psc + sign(-psc);
      ll dif = max(a[i], trg) - min(a[i], trg);
      ans2 += dif;
      psc += trg;
    }
  }
  
  cout << ans2 << endl;
}