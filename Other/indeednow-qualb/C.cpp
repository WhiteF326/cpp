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


int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        g[--x].push_back(--y);
        g[y].push_back(x);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(0);
    bool visited[n] = {false};
    visited[0] = true;
    queue<int> ans;
    
    while(!q.empty()){
        int dest = q.top();
        q.pop();
        ans.push(dest + 1);

        for(int v : g[dest]){
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }

    for(int i = 1; i < n; i++) {
        cout << ans.front() << " ";
        ans.pop();
    }cout << ans.front() << endl;
}