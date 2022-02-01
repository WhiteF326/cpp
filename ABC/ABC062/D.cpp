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
  
  int n; cin >> n;
  vector<ll> a(3 * n);
  aryin(a, 3 * n);

  vector<ll> s(n * 2 + 1, 0);
  priority_queue<ll, vector<ll>, greater<ll>> lq;
  for(int i = 0; i < n; i++){
    s[i + 1] = s[i] + a[i];
    lq.push(a[i]);
  }
  for(int i = n; i < n * 2; i++){
    ll m = lq.top();
    if(a[i] > m) {
      s[i + 1] = s[i] - m + a[i];
      lq.pop();
      lq.push(a[i]);
    }else{
      s[i + 1] = s[i];
    }
  }
  vector<ll> t(n * 2 + 1, 0);
  priority_queue<ll> rq;
  for(int i = 0; i < n; i++){
    t[i + 1] = t[i] + a[n * 3 - 1 - i];
    rq.push(a[n * 3 - 1 - i]);
  }
  for(int i = n; i < n * 2; i++){
    ll m = rq.top();
    if(a[n * 3 - 1 - i] < m) {
      t[i + 1] = t[i] - m + a[n * 3 - 1 - i];
      rq.pop();
      rq.push(a[n * 3 - 1 - i]);
    }else{
      t[i + 1] = t[i];
    }
  }
  
  ll ans = LLONG_MIN;
  for(int i = n; i <= n * 2; i++){
    chmax(ans, s[i] - t[n * 3 - i]);
  }cout << ans << endl;
}