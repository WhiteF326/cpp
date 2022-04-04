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
    
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n * 2);
    
    vector<int> a(n), b(n);
    aryin(a, n);
    aryin(b, n);

    for(int i = 0; i < n - 1; i++){
        if(abs(a[i] - a[i + 1]) <= k){
            g[i * 2].emplace_back(i * 2 + 2);
        }
        if(abs(a[i] - b[i + 1]) <= k){
            g[i * 2].emplace_back(i * 2 + 3);
        }
        if(abs(b[i] - a[i + 1]) <= k){
            g[i * 2 + 1].emplace_back(i * 2 + 2);
        }
        if(abs(b[i] - b[i + 1]) <= k){
            g[i * 2 + 1].emplace_back(i * 2 + 3);
        }
    }

    queue<int> q;
    q.push(0);
    q.push(1);

    vector<bool> visited(2 * n, false);
    visited[0] = true;
    visited[1] = true;

    while(!q.empty()){
        int dest = q.front();
        q.pop();

        for(int v : g[dest]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
    }

    if(visited[n * 2 - 2] || visited[n * 2 - 1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
