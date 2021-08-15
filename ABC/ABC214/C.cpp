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

int main(){
  int n; cin >> n;
  vector<ll> s(n), t(n);
  for(int i = 0; i < n; i++) cin >> s[i];
  for(int i = 0; i < n; i++) cin >> t[i];

  vector<ll> fast(n, INT_MAX);
  
  for(int j = 0; j < 2; j++){
    for(int i = 0; i < n; i++){
      fast[i] = min(t[i], fast[(i - 1 + n) % n] + s[(i - 1 + n) % n]);
    }
  }
  for(int i = 0; i < n; i++){
    cout << fast[i] << endl;
  }
}