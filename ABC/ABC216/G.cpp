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
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i = 0; i < n; i++){
        g[i].push_back({i + 1, 1});
        g[i + 1].push_back({i, 0});
    }
    for(int i = 0; i < m; i++){
        int l, r, x; cin >> l >>r >> x;
        g[l - 1].push_back({r, r - l + 1 - x});
    }

    vector<int> d(n + 1, 1 << 25);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto p = q.top();
        q.pop();

        if(d[p.second] != p.first) continue;
        for(auto v : g[p.second]){
            if(d[v.first] > d[p.second] + v.second){
                d[v.first] = d[p.second] + v.second;
                q.push({d[v.first], v.first});
            }
        }
    }

    for(int i = 0; i < n; i++) cout << 1 - (d[i + 1] - d[i]) << " ";
    cout << endl;
}
