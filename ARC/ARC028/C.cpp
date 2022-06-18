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
vector<vector<int>> g(100000);
bool visited[100000];
vector<int> sb(100000, 1);
vector<int> ans(100000, 0);

void subd(int p){
    for(int v : g[p]){
        if(visited[v]) continue;
        visited[v] = 1;
        subd(v);
        sb[p] += sb[v];
    }
}

void dp(int p){
    //
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 1; i < n; i++){
        int a; cin >> a;
        g[i].push_back(a);
        g[a].push_back(i);
    }

    visited[0] = 1;
    subd(0);
    dp(0);
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
    fflush(stdout);
}
