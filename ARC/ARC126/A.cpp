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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int t; cin >> t;
  query(t){
    ll a, b, c; cin >> a >> b >> c;
    b /= 2;
    ll ans = 0;
    ans += min(b, c);
    b -= ans, c -= ans;

    ll s1 = min(b, a / 2);
    b -= s1, a -= s1 * 2;
    ans += s1;

    ll s2 = min(c / 2, a);
    a -= s2, c -= s2 * 2;
    ans += s2;

    ll s3 = min(c, a / 3);
    a -= s3 * 3, c -= s3;
    ans += s3;

    ll ls = a / 5;
    ans += ls;

    cout << ans << endl;
  }
}