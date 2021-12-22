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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


const ll modv = 1000000007;

int main(){
  int n; cin >> n;

  vector<ll> a(n); aryin(a, n);

  vector<ll> fb(n + 1, 1);
  for(int i = 2; i <= n; i++){
    fb[i] = (fb[i - 2] + fb[i - 1]) % modv;
  }

  ll ans = a[0] * fb[n] % modv;
  for(int i = 1; i < n; i++){
    ans = (ans + a[i] * ((fb[i] * fb[n - i]) % modv)) % modv;
    ans = (ans + modv - (a[i] * ((fb[i - 1] * fb[n - i - 1]) % modv)) % modv) % modv;
    ans %= modv;
  }

  cout << ans << endl;
}