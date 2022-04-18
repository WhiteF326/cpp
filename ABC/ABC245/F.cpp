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

    vector<int> outcount(n, 0);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[v - 1].push_back(u - 1);
        outcount[u - 1]++;
    }

    int ans = n;

    queue<int> q;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(outcount[i] == 0){
            q.push(i);
            ans--;
        }
    }

    while(!q.empty()){
        int dest = q.front();
        q.pop();

        for(int v : g[dest]){
            if(visited[v]) continue;
            outcount[v]--;

            if(outcount[v] == 0){
                q.push(v);
                ans--;
                visited[v] = true;
            }
        }
    }

    cout << ans << endl;
}
