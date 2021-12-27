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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


ll score(ll b, ll c, ll d, ll e){
  ll mx = max(b, max(c, max(d, e)));
  ll mn = min(b, min(c, min(d, e)));
  return abs(mx - mn);
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<ll> a(n); aryin(a, n);

  // center limit = n - 2
  int left = 1, center = 2, right = 3;

  // 初期スコアの計算
  ll b = 0, c = 0, d = 0, e = 0;
  for(int i = 0; i < left; i++) b += a[i];
  for(int i = left; i < center; i++) c += a[i];
  for(int i = center; i < right; i++) d += a[i];
  for(int i = right; i < n; i++) e += a[i];
  ll ans = score(b, c, d, e);

  // 初期の r を求める
  ll dd = abs(d - e);
  for(; right < n; right++){
    ll nd = d + a[right];
    ll ne = e - a[right];
    if(dd > abs(nd - ne)){
      d = nd;
      e = ne;
      dd = abs(d - e);
    }else{
      break;
    }
  }
  ans = min(ans, score(b, c, d, e));

  // cout << left << " " << center << " " << right << endl;
  // cout << b << " " << c << " " << d << " " << e << endl;
  // cout << b + c + d + e << endl;

  // 中央をずらす
  center++;
  for(; center <= n - 2; center++){
    // 左側をならす
    c += a[center - 1];
    ll bd = abs(b - c);
    for(; left < center; left++){
      ll nb = b + a[left];
      ll nc = c - a[left];
      if(bd > abs(nb - nc)){
        b = nb;
        c = nc;
        bd = abs(b - c);
      }else{
        break;
      }
    }
    // 右側をならす
    d -= a[center - 1];
    if(right < center + 1) right = center;
    ll dd = abs(d - e);
    for(; right < n; right++){
      ll nd = d + a[right];
      ll ne = e - a[right];
      if(dd > abs(nd - ne)){
        d = nd;
        e = ne;
        dd = abs(d - e);
      }else{
        break;
      }
    }

    ans = min(ans, score(b, c, d, e));
    // cout << left << " " << center << " " << right << endl;
    // cout << b << " " << c << " " << d << " " << e << endl;
    // cout << b + c + d + e << endl;
  }

  cout << ans << endl;
}