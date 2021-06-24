#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, p, q; cin >> n >> p >> q;
  vector<ll> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    // a[i] %= p;
  }
  ll ans = 0;
  for(int i = 0; i < n - 4; i++){
    for(int j = i + 1; j < n - 3; j++){
      for(int k = j + 1; k < n - 2; k++){
        for(int l = k + 1; l < n - 1; l++){
          for(int m = l + 1; m < n; m++){
            if(a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}