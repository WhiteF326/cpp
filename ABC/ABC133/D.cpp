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
  vector<ll> x(n);
  for(int i = 0; i < n; i++) cin >> x[i];

  ll sum = 0;
  for(int i = 0; i < n; i++){
    sum += (i % 2 ? -1 : 1) * x[i];
  }

  vector<ll> ans(n);
  ans[0] = sum;
  for(int i = 0; i < n - 1; i++){
    ans[i + 1] = x[i] * 2 - ans[i];
  }
  for(int i = 0; i < n - 1; i++) cout << ans[i] << " ";
  cout << ans[n - 1] << endl;
}