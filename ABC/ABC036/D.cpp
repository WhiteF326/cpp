#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int n;
vector<vector<int>> g(100000);
vector<bool> visited(100000, 0);
#define mint modint1000000007
vector<vector<mint>> dp(100000, vector<mint>(2, 1));

void ddp(int p){
    int c = 0;
    for(int v : g[p]){
        if(visited[v]) continue;
        c++;
        visited[v] = 1;
        ddp(v);

        // dp
        dp[p][0] *= dp[v][0] + dp[v][1];
        dp[p][1] *= dp[v][0];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    visited[0] = 1;
    ddp(0);

    cout << (dp[0][0] + dp[0][1]).val() << endl;
}