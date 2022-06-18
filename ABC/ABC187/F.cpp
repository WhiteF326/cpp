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
// u が部分集合 t の部分集合になる
#define subset(u, t) for(int u = t; u > 0; u = (u - 1) & t)
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int pc(int b){
    int res = 0;
    while(b){
        res += (b & 1);
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a][b] = true;
        g[b][a] = true;
    }

    vector<int> dp(1 << n, 1 << 18);
    for(int t = 1; t < (1 << n); t++){
        int es = 0, p = pc(t);
        for(int x = 0; x < n; x++){
            if(!(t & (1 << x))) continue;
            for(int y = 0; y < n; y++){
                if(!(t & (1 << y))) continue;
                es += g[x][y];
            }
        }
        if(es == p * (p - 1)) dp[t] = 1;
        else{
            subset(u, t){
                chmin(dp[t], dp[u] + dp[t ^ u]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
