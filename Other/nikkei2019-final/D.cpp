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


struct S{
    ll value;
    ll size;
};
S op(S a, S b){
    return {a.value + b.value, a.size + b.size};
}
S e(){
    return {0, 0};
}
S mapping(ll f, S x){
    if(f != 8e18){
        return {f * x.size, x.size};
    }else{
        return x;
    }
}
ll composition(ll f, ll g){
    if(f == 8e18){
        return g;
    }else{
        return f;
    }
}
ll id(){
    return 8e18;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<S> v(n, {0, 1});
    lazy_segtree<S, op, e, ll, mapping, composition, id> seg(v);
    int b = 0;
    ll ans = 0;
    query(m){
        int t, l, r; cin >> t >> l >> r;
        ans += (ll)t * (r - l + 1) - seg.prod(l - 1, r).value;
        seg.apply(l - 1, r, t);
    }
    cout << ans << endl;
}
