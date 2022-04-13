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


int op(int a, int b){
    return a + b;
}
int e(){
    return 0;
}
int ptr;

bool f(int x){
    return x < ptr;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q; cin >> q;
    segtree<int, op, e> seg(200001);

    query(q){
        int t, x; cin >> t >> x;
        if(t == 1){
            seg.set(x, 1);
        }else{
            ptr = x;
            int ans = seg.max_right<f>(0);
            cout << ans << endl;
            seg.set(ans, 0);
        }
    }
}