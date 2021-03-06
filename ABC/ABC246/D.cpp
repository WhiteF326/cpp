#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


ll f(ll a, ll b){
    return a * a * a + a * a * b + a * b * b + b * b * b;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll ans = LLONG_MAX;

    ll b = 1000000;
    for(ll a = 0; a <= 1000000; a++){
        while(f(a, b) >= n && b >= 0) b--;
        b++;
        // cout << a << " " << b << endl;
        chmin(ans, f(a, b));
    }
    cout << ans << endl;
}
