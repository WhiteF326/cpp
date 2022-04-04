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


int n;
vector<vector<int>> g(100000);
vector<bool> visited(100000, 0);

#define mint modint1000000007
vector<vector<mint>> dp(100000, vector<mint>(2, 0));

void rev(int p){
    int r = 0;

    mint b = 1, w = 1;
    for(int v : g[p]){
        if(visited[v]) continue;
        r++;
        visited[v] = true;
        rev(v);

        // w->w w->b b->w のみ
        b *= dp[v][0];
        w *= dp[v][0] + dp[v][1];
    }

    if(!r){
        dp[p][0] = 1;
        dp[p][1] = 1;
    }else{
        dp[p][0] = w;
        dp[p][1] = b;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        g[x - 1].emplace_back(y - 1);
        g[y - 1].emplace_back(x - 1);
    }

    visited[0] = true;
    rev(0);

    cout << (dp[0][0] + dp[0][1]).val() << endl;
}
