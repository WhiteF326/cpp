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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    vector<vector<ll>> dist(1 << n, vector<ll>(n, 0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        dist[1 << i][i] = 1;
        q.push({1 << i, i});
    }

    while(!q.empty()){
        int bit = q.front().first, dest = q.front().second;
        q.pop();

        for(int v : g[dest]){
            int nbit = bit ^ (1 << v);
            if(dist[nbit][v] == 0){
                dist[nbit][v] = dist[bit][dest] + 1;
                q.push({nbit, v});
            }
        }
    }

    ll ans = 0;
    for(int bit = 1; bit < (1 << n); bit++){
        ans += *min_element(all(dist[bit]));
    }
    cout << ans << endl;
}
