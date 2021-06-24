#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  ll ans = 0;
  map<int, ll> a, b, c;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a[x % 46]++;
  }
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    b[x % 46]++;
  }
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    c[x % 46]++;
  }
  for(int i = 0; i < 46; i++){
    for(int j = 0; j < 46; j++){
      for(int k = 0; k < 46; k++){
        if((i + j + k) % 46) continue;
        ans += a[i] * b[j] * c[k];
      }
    }
  }
  cout << ans << endl;
}