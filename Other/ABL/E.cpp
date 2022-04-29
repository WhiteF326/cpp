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


#define modv 998244353
#define mint modint998244353

vector<mint> tl(200011), dl(200011);

struct Digit{
    mint value;
    int size;
};

Digit op(Digit a, Digit b){
    return {a.value * tl[b.size] + b.value, a.size + b.size};
}
Digit e(){
    return {0, 0};
}
Digit mapping(int f, Digit x){
    if(f == 0) return x;
    return {f * dl[x.size], x.size};
}
int composition(int f, int g){
    if(f == 0) return g;
    else return f;
}
int id(){
    return 0;
}
void d_initialize(){
    tl[0] = 1;
    for(int i = 0; i < 200010; i++) tl[i + 1] = tl[i] * 10;
    dl[0] = 0;
    for(int i = 0; i < 200010; i++){
        dl[i + 1] = dl[i] * 10 + 1;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    d_initialize();

    int n, q; cin >> n >> q;
    vector<Digit> init(n, {1, 1});
    lazy_segtree<Digit, op, e, int, mapping, composition, id> seg(init);

    query(q){
        int l, r, d; cin >> l >> r >> d;
        seg.apply(l - 1, r, d);
        cout << seg.all_prod().value.val() << endl;
    }
}
