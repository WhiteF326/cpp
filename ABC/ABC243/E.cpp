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


struct Edge{
    int l, r;
    ll w;
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<Edge> vl(m);
    vector<vector<ll>> d(n, vector<ll>(n, 1LL << 60));
    for(int i = 0; i < n; i++) d[i][i] = 0;
    for(int i = 0; i < m; i++){
        int a, b; ll c; cin >> a >> b >> c;
        a--, b--;
        vl[i] = {a, b, c};
        d[a][b] = c;
        d[b][a] = c;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        bool last = false;
        for(int k = 0; k < n; k++){
            if(vl[i].l == k || vl[i].r == k) continue;
            if(d[vl[i].l][k] + d[k][vl[i].r] <= vl[i].w){
                last = true;
            }
        }
        ans += last;
    }
    cout << ans << endl;
}
