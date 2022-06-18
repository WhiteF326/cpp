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


struct Food{
    int a, b;
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, t; cin >> n >> t;
    // dp[i][j] = i 個目の料理を選ぶか選ばないか決めたとき食べ終わるのに
    // 累計 j 分かかるとして、達成できる美味しさの総和
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, INT_MIN));
    dp[0][0] = 0;

    vector<Food> f(n);
    for(int i = 0; i < n; i++) cin >> f[i].a >> f[i].b;
    sort(all(f), [](const Food& a, const Food& b){
        return a.a < b.a;
    });

    for(int i = 0; i < n; i++){
        for(int j = 0; j < t; j++){
            if(dp[i][j] == INT_MIN) continue;
            // 食べる場合
            chmax(dp[i + 1][min(t, j + f[i].a)], dp[i][j] + f[i].b);
            // 食べない場合
            chmax(dp[i + 1][j], dp[i][j]);
        }
        // 時間がいっぱいになっている場合
        chmax(dp[i + 1][t], dp[i][t]);
    }

    int ans = 0;
    for(int i = 0; i <= t; i++){
        chmax(ans, dp[n][i]);
    }
    cout << ans << endl;
}
