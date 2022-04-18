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
    vector<vector<int>> g(n * 3, vector<int>(0));
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        for(int i = 0; i < 3; i++){
            g[u * 3 + i].push_back(v * 3 + ((i + 1) % 3));
        }
    }

    int s, t; cin >> s >> t;
    s--, t--;

    queue<int> q;
    q.push(s * 3);
    vector<bool> visited(n * 4, 0);
    visited[s * 3] = 1;
    vector<int> dist(n * 4, 0);

    while(!q.empty()){
        int dest = q.front();
        q.pop();

        for(auto v : g[dest]){
            if(visited[v]) continue;
            visited[v] = 1;
            dist[v] = dist[dest] + 1;
            q.push(v);
        }
    }

    if(visited[t * 3]){
        cout << dist[t * 3] / 3 << endl;
    }else{
        cout << -1 << endl;
    }
}
