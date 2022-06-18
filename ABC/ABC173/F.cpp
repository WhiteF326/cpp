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


int n;
vector<vector<int>> g(200000);
bool vis[200000];
vector<ll> dp(200000, 0);

void tdp(int p){
    for(int v : g[p]){
        if(vis[v]) continue;
        vis[v] = true;
        tdp(v);
        if(v < p){
            dp[v]++;
            dp[p]--;
        }
    }
}

ll ans = 0;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vis[0] = true;
    tdp(0);
    for(int i = 1; i < n; i++) dp[i] += dp[i - 1];
    for(int i = 0; i < n; i++) dp[i]++;

    ll res = accumulate(all(dp), 0LL);
    cout << res << endl;

    for(int i = 0; i < n; i++){
        ans += res;
        for(int v : g[i]){
            if(v > i) res -= v - i;
        }
        cout << res << endl;
    }

    cout << ans << endl;
}
