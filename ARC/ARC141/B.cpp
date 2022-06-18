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


#define modv 998244353
#define mint modint998244353
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    /**
     * Top bit が大きくなるようにしなくてはいけない
     * n > 60 または n > log_2 M だったら構成不可能？
    */
    int lst = 0; ll cpy = m;
    while(cpy) lst++, cpy >>= 1;
    if(n > lst){
        cout << 0 << endl;
        return 0;
    }

    // top bit が b 桁目である整数の個数
    auto rng = [&](int b){
        ll mn = 1LL << (b - 1);
        ll lim = min(m, (1LL << b) - 1);
        return max(0LL, lim - mn + 1);
    };

    // dp[i][j] = B_i の top bit が j
    vector<vector<mint>> dp(n + 1, vector<mint>(lst + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= lst; j++){
            for(int next = j + 1; next <= lst; next++){
                dp[i + 1][next] += dp[i][j] * rng(next);
            }
        }
    }

    mint ans = 0;
    for(int i = 1; i <= lst; i++){
        ans += dp[n][i];
    }
    cout << ans.val() << endl;
}
