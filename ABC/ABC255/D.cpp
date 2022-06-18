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


ll op(ll a, ll b){
    return a + b;
}
ll e(){
    return 0;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    aryin(a, n);
    sort(all(a));

    segtree<ll, op, e> seg(a);

    query(q){
        ll x; cin >> x;
        ll ans = 0;
        int rpos = upper_bound(all(a), x) - a.begin();
        ll rsum = seg.prod(rpos, n);
        ans += rsum - (n - rpos) * x;
        int lpos = lower_bound(all(a), x) - a.begin();
        ll lsum = seg.prod(0, lpos);
        ans += x * lpos - lsum;

        cout << ans << "\n";
    }
}
