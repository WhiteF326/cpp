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


struct Flower{
    ll h, a;
};
ll op(ll a, ll b){
    return max(a, b);
}
ll e(){
    return 0;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;

    vector<Flower> f(n);
    for(int i = 0; i < n; i++) cin >> f[i].h;
    for(int i = 0; i < n; i++) cin >> f[i].a;

    // dp[i][j] = i 番目までで最後の高さが j であるようなものの美しさの最大値
    segtree<ll, op, e> seg(n + 1);

    for(int i = 1; i <= n; i++){
        seg.set(f[i - 1].h, seg.prod(0, f[i - 1].h) + f[i - 1].a);
    }

    cout << seg.all_prod() << endl;
}
