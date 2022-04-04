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


int op(int a, int b){
    return a + b;
}
int e(){
    return 0;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w, m; cin >> h >> w >> m;
    vector<vector<int>> hl(h + 1, {w}), wl(w + 1, {h});

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        hl[x].push_back(y);
        wl[y].push_back(x);
    }

    for(int i = 0; i < h; i++) sort(all(hl[i]));
    for(int i = 0; i < w; i++) sort(all(wl[i]));

    ll res = 0;
    for(int i = 0; i < hl[0][0]; i++){
        res += wl[i][0];
    }

    segtree<int, op, e> seg(w + 1);
    for(int i = hl[0][0]; i < w; i++){
        seg.set(i, 1);
    }
    for(int i = 0; i < wl[0][0]; i++){
        res += seg.prod(0, hl[i][0]);
        for(int v : hl[i]){
            seg.set(v, 1);
        }
    }

    cout << res << endl;
}
