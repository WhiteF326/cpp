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

int n, start;
vector<vector<int>> g(150000);
vector<bool> visited(150000, false);
int in[150000], out[150000];
int t = 0;

void dfs(int p){
    in[p] = t;
    t++;

    for(int v : g[p]){
        if(visited[v]) continue;
        visited[v] = true;

        dfs(v);

        t++;
    }
    out[p] = t;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        if(p == -1){
            start = i;
        }else{
            g[p - 1].push_back(i);
            g[i].push_back(p - 1);
        }
    }

    visited[start] = true;
    dfs(start);

    int q; cin >> q;
    query(q){
        int a, b; cin >> a >> b;
        a--, b--;
        if(in[b] <= in[a] && out[a] <= out[b]){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << endl;
        }
    }
}
