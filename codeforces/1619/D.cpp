#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define x_query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


#define blim 100000
template <typename T>
struct SegTree {
    const T INF = T();
    int n;
    vector<T> dat, lazy;
    SegTree(int n_) : n(), dat(n_ * 4, INF), lazy(n_ * 4, INF) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = INF;
    }
    void update(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            if(dat[k * 2 + 1].count() >= dat[k * 2 + 2].count()){
                dat[k] = dat[k * 2 + 1];
            }else{
                dat[k] = dat[k * 2 + 2];
            }
        }
    }
    void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            if(vl.count() >= vr.count()){
                return vl;
            }else{
                return vr;
            }
        }
    }
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    /* debug */
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main(){
    int t; cin >> t;
    x_query(t){
        int n, m;
        scanf("%d%d", &m, &n);

        int left = 0, right = 1000000000;
        int mid = 0;

        vector<vector<int>> vs(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> vs[i][j];
            }
        }

        int ans = 0;

        while(right - left > 1){
            mid = (right + left) / 2;

            // mid を基準に配列を変換する
            vector<bitset<blim>> vl(m);
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(vs[i][j] >= mid) vl[i].set(j, true);
                    else vl[i].set(j, false);
                }
            }

            SegTree<bitset<blim>> seg(m);
            for(int i = 0; i < m; i++){
                auto x = seg.query(i, i + 1);
                seg.update(i, i + 1, x | vl[i]);
            }

            if(seg.query(0, n).count() == n){
                left = mid;
            }else{
                right = mid;
            }
        }

        cout << right << endl;
    }
}