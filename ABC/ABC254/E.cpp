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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> dis(n, vector<int>(4, 0));

    for(int i = 0; i < n; i++){
        queue<int> q;
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        visited[i] = true;
        dist[i] = 0;
        q.push(i);
        dis[i][0] += i + 1;
        
        while(!q.empty()){
            int dest = q.front();
            q.pop();

            for(int v : g[dest]){
                if(visited[v]) continue;
                visited[v] = true;
                dist[v] = dist[dest] + 1;
                if(dist[v] <= 3){
                    dis[i][dist[v]] += v + 1;
                    q.push(v);
                }
            }
        }
    }

    int q; cin >> q;
    query(q){
        int x, k; cin >> x >> k;
        x--;
        ll ans = 0;
        for(int i = 0; i <= k; i++){
            ans += dis[x][i];
        }
        cout << ans << "\n";
    }
    fflush(stdout);
}
