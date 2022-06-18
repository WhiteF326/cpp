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
    return min(a, b);
}
ll e(){
    return LLONG_MAX;
}
ll mapping(ll f, ll x){
    return f + x;
}
ll composition(ll f, ll g){
    return f + g;
}
ll id(){
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    auto conv = [&](int pos){
        if(pos % 2){
            return pos / 2 + n / 2 + (n % 2);
        }else{
            return pos / 2;
        }
    };
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[conv(i)];
    
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(c);

    int q; cin >> q;
    int harf = n / 2 + (n % 2);

    ll ans = 0;
    query(q){
        int t; cin >> t;
        if(t == 1){
            int x; ll a; cin >> x >> a;
            x = conv(x - 1);
            if(seg.prod(x, x + 1) >= a){
                seg.apply(x, -a);
                ans += a;
            }
        }else if(t == 2){
            ll a; cin >> a;
            if(seg.prod(0, harf) >= a){
                seg.apply(0, harf, -a);
                ans += a * harf;
            }
        }else{
            ll a; cin >> a;
            if(seg.prod(0, n) >= a){
                seg.apply(0, n, -a);
                ans += a * (ll)n;
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << seg.prod(conv(i), conv(i) + 1) << " ";
        // }cout << endl;
    }

    cout << ans << endl;
}
