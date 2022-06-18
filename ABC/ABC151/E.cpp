#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x) 42;
#define printarray(x) 42;
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


#define modv 1000000007
#define mint modint1000000007
ll modpow(ll x, ll n, int mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    aryin(a, n);
    sort(all(a));

    vector<ll> b(all(a));
    for(int i = 1; i < n; i++) b[i] += b[i - 1];

    if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    ll s = 0, ans = 0, sr = n - k + 1;
    // i じゃなくて kCk-2 っぽい
    for(int i = 0; i + k - 1 < n; i++) s += a[i + k - 1] * i;

    for(int i = 0; i <= n - k; i++){
        ll res = (s - a[i] * sr) % modv;
        ans = (res + ans) % modv;
        s -= b[n - 1] - b[i + k - 2];
        sr--;
        cout << res << endl;
    }
    cout << ans << endl;
}
