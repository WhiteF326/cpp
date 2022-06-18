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
    return 0LL;
}
ll mapping(ll f, ll x){
    return f + x;
}
ll composition(ll f, ll g){
    return f + g;
}
ll id(){
    return 0LL;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, q; cin >> n >> m >> q;
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(m);

    vector<int> t(q, 0);
    vector<int> l1(q, 0), r1(q, 0); vector<ll> x1(q, 0);
    vector<int> i2(q, 0); vector<ll> x2(q, 0);
    vector<int> i3(q, 0), j3(q, 0);

    for(int i = 0; i < q; i++){
        cin >> t[i];
        if(t[i] == 1) cin >> l1[i] >> r1[i] >> x1[i];
        if(t[i] == 2) cin >> i2[i] >> x2[i];
        if(t[i] == 3) cin >> i3[i] >> j3[i];
    }

    vector<unordered_map<int, ll>> g(n);
    for(int i = 0; i < q; i++){
        if(!i3[i]) continue;
        g[i3[i] - 1][j3[i] - 1] = 0;
    }

    for(int i = 0; i < q; i++){
        if(t[i] == 1){
            seg.apply(l1[i] - 1, r1[i], x1[i]);
        }else if(t[i] == 2){
            i2[i]--;
            for(auto d : g[i2[i]]){
                g[i2[i]][d.first] = seg.get(d.first) - x2[i];
            }
        }else{
            cout << seg.get(j3[i] - 1) - g[i3[i] - 1][j3[i] - 1] << "\n";
        }
    }
}
