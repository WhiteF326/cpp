#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> accl(n + 1, 0);
  for(int i = 1; i < n + 1; i++){
    accl[i] = accl[i - 1] + a[i - 1];
  }
  vector<ll> d_accl(n + 1, 0);
  for(int i = 1; i < n + 1; i++){
    d_accl[i] = d_accl[i - 1] + accl[i - 1];
  }
  ll mx = 0;
  for(int i = 0; i < n; i++){
    mx = max(mx, a[i]);
    cout << accl[i + 1] + mx * (i + 1) + d_accl[i + 1] << endl;
  }
}
