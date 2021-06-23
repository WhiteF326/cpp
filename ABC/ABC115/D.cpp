#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;
  ll x; cin >> x;
  vector<ll> m(51, 1);
  for(int i = 1; i <= 50; i++) m[i] = m[i - 1] * 2 + 3;
  vector<ll> p(51, 1);
  for(int i = 1; i <= 50; i++) p[i] = p[i - 1] * 2 + 1;
  
  ll ans = 0;
  for(int i = n; i >= 2; i--){
    if(x == m[i]){
      // 一番上
      cout << ans + p[i] << endl;
      return 0;
    }else if(x == m[i - 1] + 2){
      // 中央
      cout << ans + p[i - 1] + 1 << endl;
      return 0;
    }else if(x == 1){
      cout << ans << endl;
      return 0;
    }else{
      if(x > m[i - 1] + 2){
        x -= (m[i - 1] + 1);
        ans += p[i - 1] + 1;
      }
      x--;
    }
  }
  vector<int> last = {0, 0, 1, 2, 3, 3};
  ans += last[x];

  cout << ans << endl;
}