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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;

    ll ans = LLONG_MAX;

    for(ll a = 0; a <= 1000001; a++){
        ll mn = LLONG_MAX;
        ll l = -1, r = 1000002;
        while(r - l > 1){
            ll mid = l + (r - l) / 2;

            ll f = a * a * a + a * a * mid + a * mid * mid + mid * mid * mid;
            // cout << f << endl;
            if(f >= n){
                r = mid;
                chmin(mn, f);
            }else{
                l = mid;
            }
        }

        chmin(ans, mn);
    }

    cout << ans << endl;
}
