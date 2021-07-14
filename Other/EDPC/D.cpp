#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(arr) arr.begin(), arr.end()
using ll = long long;
using ld = long double;

int main(){
  int n, w; cin >> n >> w;
  vector<pair<int, ll>> p(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    p[i] = mp(a, b);
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= w; j++){
      //
    }
  }
}