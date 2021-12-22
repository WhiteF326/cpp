#include <bits/stdc++.h>
using namespace std;
#include <atcoder/lazysegtree>
using namespace atcoder;

using ll = long long;


// Euler Tour
vector<int> vis;
vector<ll> edges(1, 0);
vector<vector<pair<int, ll>>> g(100000);
vector<int> in(100000);
vector<int> out(100000);
vector<int> seen(100000, false);
int t = 0;

void dfs(int p){
    in[p] = t;
    t++;
    vis.push_back(p);
    seen[p] = true;
    
    for(auto v : g[p]){
        if(seen[v.first]) continue;
        edges.push_back(v.second);
        dfs(v.first);
        vis.push_back(p);
        edges.push_back(0);
    }

    t++;
    out[p] = t;
}

// lazy segtree
ll ID = 8000000000000000000;
ll op(ll a, ll b){
    return a ^ b;
}
ll e(){
    return 0;
}
ll mapping(ll f, ll x){
    if(f == ID){
        return x;
    }else{
        return f;
    }
}
ll composition(ll f, ll g){
    if(f == ID){
        return g;
    }else{
        return f;
    }
}
ll id(){
    return ID;
}

// main
int main(){
    ifstream ifs("02_break_01.txt");
    int n; ifs >> n;
    assert(2 <= n && n <= 100000);
    for(int i = 0; i < n - 1; i++){
        int l, r; ifs >> l >> r;
        assert(1 <= l && l <= n && 1 <= r && r <= n);
        ll a; ifs >> a;
        assert(0 <= a && a <= 1000000000000000000);
        g[l - 1].push_back({r - 1, a});
        g[r - 1].push_back({l - 1, a});
    }

    vis.reserve(n * 2);
    edges.reserve(n * 2);

    dfs(0);
    edges.push_back(0);

    int m = vis.size();
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(edges);

    int q; ifs >> q;
    assert(1 <= q && q <= 100000);
    for(int i = 0; i < q; i++){
        int t; ifs >> t;
        assert(t == 1 || t == 2);
        int x; ifs >> x;
        if(t == 1){
            // delete
            assert(2 <= x && x <= n);
            seg.apply(in[x - 1], out[x - 1], 0);
        }else{
            // f(x)
            assert(1 <= x && x <= n);
            cout << seg.prod(in[x - 1] + 1, out[x - 1]) << endl;
        }
    }
}