#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n, k; cin >> n >> k;
  vector<ll> pl(0), mx(0);
  for(int i = 0; i < n; i++){
    ll a; cin >> a;
    if(a > 0) pl.emplace_back(a);
    else mx.emplace_back(a);
  }
  ll ans = 1;
  int diff = n - k;
  sort(all(pl), greater<ll>());
  sort(all(mx));

  if(mx.size() == n){
    // corner case
    ll ans = 1;
    if(k % 2){
      sort(all(mx), [](ll a, ll b){
        return abs(a) < abs(b);
      });
    }else{
      sort(all(mx), [](ll a, ll b){
        return abs(a) > abs(b);
      });
    }
    for(int i = 0; i < k; i++){
      ans *= (mx[i] + modv);
      ans %= modv;
    }
    cout << ans << endl;
    return 0;
  }
  if(n == k){
    for(int v : pl){
      ans *= v;
      ans %= modv;
    }
    for(int v : mx){
      ans *= (v + modv);
      ans %= modv;
    }

    cout << ans << endl;
    return 0;
  }

  bool ismin = mx.size() % 2;
  if(diff % 2){
    if(mx.size() % 2){
      mx.pop_back();
      ismin = !ismin;
    }else if(pl.size() >= 1){
      pl.pop_back();
    }else{
      mx.pop_back();
      ismin = !ismin;
    }
    diff--;
  }
  if(ismin && pl.size() && diff >= 2){
    pl.pop_back();
    mx.pop_back();
    diff -= 2;
  }
  for(int i = 0; i < diff / 2; i++){
    if(pl.size() < 2){
      mx.pop_back();
      mx.pop_back();
    }else if(mx.size() < 2){
      pl.pop_back();
      pl.pop_back();
    }else{
      ll plx = pl[pl.size() - 1] * pl[pl.size() - 2];
      ll mnx = mx[mx.size() - 1] * mx[mx.size() - 2];
      if(plx < mnx){
        pl.pop_back();
        pl.pop_back();
      }else{
        mx.pop_back();
        mx.pop_back();
      }
    }
  }
  for(int v : pl){
    ans *= v;
    ans %= modv;
  }
  for(int v : mx){
    ans *= (v + modv);
    ans %= modv;
  }

  cout << ans << endl;
}