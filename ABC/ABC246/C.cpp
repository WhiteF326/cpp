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
    
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    aryin(a, n);
    

    ll ans = 0;
    for(ll &v : a){
        if(v >= x){
            ll c = min(k, v / x);
            v -= c * x;
            k -= c;
        }
    }

    sort(all(a), greater<ll>());

    for(ll &v : a){
        if(k >= 1){
            k--;
            v = max(0LL, v - x);
        }
    }
    
    cout << accumulate(all(a), 0LL) << endl;
}
