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
  int s, t; cin >> s >> t;
  int ans = 0;
  for(int a = 0; a <= 100; a++){
    for(int b = 0; b <= 100; b++){
      for(int c = 0; c <= 100; c++){
        if(a + b + c <= s && a * b * c <= t) ans++;
      }
    }
  }
  cout << ans << endl;
}