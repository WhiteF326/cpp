#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  ll ans = 0;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  
  for(int i = 0; i < n; i++){
    ans += llabs(a[i] - b[i]);
  }
  // 操作回数がk以内でかつ偶奇も一致するなら
  if(ans <= k && k % 2 == ans % 2) cout << "Yes" << endl;
  else cout << "No" << endl;
}