#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j)
using ll = long long;
using ld = long double;

int op(int a, int b){
  return max(a, b);
}

int e(){
  return 0;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  ll ans = a[0] * b[0];
  cout << ans << endl;
  
  ll t_max = a[0];
  for(int i = 1; i < n; i++){
    t_max = max(t_max, a[i]);
    ans = max(t_max * b[i], ans);
    ans = max(a[i] * b[i], ans);
    cout << ans << endl;
  }
}