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
    int count;
    int size;
};
S op(S a, S b){
    return {a.count + b.count, a.size + b.size};
}
S e(){
    return {0, 0};
}
S mapping(bool f, S x){
    if(f){
        x.count = x.size - x.count;
    }
    return x;
}
bool composition(bool f, bool g){
    return f ^ g;
}
bool id(){
    return 0;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, q; cin >> n >> q;
    lazy_segtree<S, op, e, bool, mapping, composition, id> seg(vector<S>(n, {0, 1}));

    query(q){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            seg.apply(l, r, 1);
        }else{
            cout << seg.prod(l, r).count << "\n";
        }
    }
}
