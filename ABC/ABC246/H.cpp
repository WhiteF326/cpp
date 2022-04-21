#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint998244353
#define mtrx vector<vector<mint>>
mtrx mtrxMul(mtrx &a, mtrx &b) {
    mtrx res(a.size(), vector<mint>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < b.size(); k++){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
mtrx op(mtrx a, mtrx b){
    return mtrxMul(a, b);
}
mtrx e(){
    return {{mint(1), mint(0)}, {mint(0), mint(1)}};
}

mtrx d = {{mint(1), mint(0)}, {mint(1), mint(0)}};      // 0
mtrx u = {{mint(0), mint(1)}, {mint(0), mint(1)}};      // 1
mtrx r = {{mint(1), mint(1)}, {mint(1), mint(1)}};      // ?
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;
    vector<mtrx> a(n);
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        switch(s[i]){
            case '0':
                a[i] = d;
                break;
            case '1':
                a[i] = u;
                break;
            case '?':
                a[i] = r;
                break;
        }
    }

    segtree<mtrx, op, e> seg(a);

    query(q){
        int x; char c; cin >> x >> c;
        switch(c){
            case '0':
                seg.set(x - 1, d);
                break;
            case '1':
                seg.set(x - 1, u);
                break;
            case '?':
                seg.set(x - 1, r);
                break;
        }
        mtrx p = seg.all_prod();
        mint ans = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                ans += p[i][j];
            }
        }
        cout << ans.val() << "\n";
    }
    fflush(stdout);
}