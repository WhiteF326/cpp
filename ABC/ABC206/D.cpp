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
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }

  dsu d(200000);
  for(int i = 0; i < n / 2; i++){
    d.merge(a[i], a[n - 1 - i]);
  }

  ll ans = 0;
  for(auto ld : d.groups()){
    ans += ld.size() - 1;
  }
  cout << ans << endl;
}