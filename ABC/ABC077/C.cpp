#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++) cin >> b[i];
  sort(b.begin(), b.end());
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(c.begin(), c.end());
  
  vector<ll> bc(n);
  for(int i = 0; i < n; i++){
    // b[i]より大きいcの要素数
    bc[i] = c.end() - upper_bound(c.begin(), c.end(), b[i]);
  }
  
}