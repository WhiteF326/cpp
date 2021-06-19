#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

const int modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> a_cs(n + 1, 0);
  for(int i = 0; i < n; i++) a_cs[i + 1] = a_cs[i] + a[i];

  ll ans = 0;
  for(int i = 0; i < n - 1; i++){
    ans += (a[i] * (a_cs[n] - a_cs[i + 1])) % modv;
  }
  cout << ans % modv << endl;
}