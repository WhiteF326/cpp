#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  ll n; cin >> n;

  string ans = "";
  while(n > 0){
    if(n % 2) ans = "A" + ans;
    ans = "B" + ans;
    n /= 2;
  }
  cout << ans << endl;
}