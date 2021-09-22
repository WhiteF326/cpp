#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  queue<ll> ansl;

  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  sort(all(a));
  ll total = accumulate(all(a), 0LL);

  int m; cin >> m;
  query(m){
    ll x, y; cin >> x >> y;

    auto v = lower_bound(all(a), x);
    if(*v == x && v != a.end()){
      ansl.push(max(0LL, y - total + x));
    }else{
      ll ans = LLONG_MAX;
      if(v != a.end()){
        ll high = *v;
        ans = max(0LL, y - total + high);
      }
      v--;
      ll low = *v;
      ll res = max(0LL, x - low);
      ans = min(ans, res + max(0LL, y - total + low));

      ansl.push(ans);
    }
  }

  while(!ansl.empty()){
    printf("%lld\n", ansl.front());
    ansl.pop();
  }
}