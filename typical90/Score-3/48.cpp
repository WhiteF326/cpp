#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  priority_queue<pair<ll, ll>> x;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    x.push(make_pair(b, a));
  }
  ll ans = 0;
  for(int i = 0; i < k; i++){
    auto dest = x.top();
    x.pop();
    ans += dest.first;
    if(dest.second != -1){
      dest.first = dest.second - dest.first;
      dest.second = -1;
      x.push(dest);
    }
  }
  cout << ans << endl;
}