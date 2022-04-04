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


ll d;
ll op(ll a, ll b){
    return (a * b) % d;
}
ll e(){
    return 1LL;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    cin >> d;
    vector<ll> a(n);
    aryin(a, n);

    segtree<ll, op, e> seg(a);

    vector<ll> s(n + 1, 0);
    map<ll, int> m;
    for(int i = 0; i < n; i++){
        s[i + 1] = (s[i] + a[i]) % d;
        m[s[i + 1]]++;
    }

    ll ans = 0;
    int r = 0;
    for(int i = 0; i < n; i++){
        if(r == i - 1){
            m[s[r + 1]]--;
            r++;
        }
        for(; r < n && seg.prod(i, r + 1); r++){
            m[s[r + 1]]--;
        }
        ans += m[s[i]];
    }

    cout << ans << endl;
}
