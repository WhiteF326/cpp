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
  auto f = [](int x){
    // a is the number made by sorting the digits of x ascendingly
    // b is the number made by sorting the digits of x descendingly
    // f(x) = b - a
    string t = to_string(x);
    sort(all(t));
    ll a = stoll(t);
    reverse(all(t));
    ll b = stoll(t);
    return b - a;
  };

  // a0 = n, a1 = f(n), a2 = f(f(n)), ...
  vector<ll> a(k + 1);
  a[0] = n;
  for(int i = 1; i <= k; i++){
    a[i] = f(a[i - 1]);
  }
  // print a[k]
  cout << a[k] << endl;
}
