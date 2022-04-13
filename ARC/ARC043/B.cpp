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


#define mint modint1000000007
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> d(n);
    aryin(d, n);
    sort(all(d));

    vector<int> cd(n, 0);
    for(int i = 0; i < n; i++){
        cd[i] = lower_bound(all(d), d[i] * 2) - d.begin();
    }
    cd.push_back(n);
    
    // dp[i][j] = i 問選択済みで、最後に選んだ問題が j 番めである
    vector<vector<mint>> dp(4, vector<mint>(n + 5, 0));
    for(int i = 0; i < n; i++) dp[0][i] = 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= n; j++){
            dp[i + 1][cd[j]] += dp[i][j];
            dp[i + 1][n] -= dp[i][j];
        }
        for(int j = 1; j <= n; j++){
            dp[i + 1][j] += dp[i + 1][j - 1];
        }
    }

    mint ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[3][i];
    }
    cout << ans.val() << endl;
}