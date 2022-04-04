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


#define mint modint1000000007
// mint dp[3004][3004];
mint op(mint a, mint b){
    return a + b;
}
mint e(){
    return mint(0);
}
vector<segtree<mint, op, e>> dp(3004, segtree<mint, op, e>(3004));
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    string s; cin >> s;

    // dp[i][j] = i 要素目まで条件を満たす順列で、まだ末尾より大きい数が j 個ある
    for(int i = 0; i < n; i++){
        dp[0].set(i, 1);
    }
    for(int i = 1; i < n; i++){
        if(s[i - 1] == '<'){
            for(int j = 0; j < n - i + 1; j++){
                dp[i].set(j, dp[i].get(j) + dp[i - 1].prod(j + 1, n - i + 1));
            }
        }else{
            for(int j = 0; j < n - i + 1; j++){
                dp[i].set(j, dp[i].get(j) + dp[i - 1].prod(0, j + 1));
            }
        }
    }

    cout << dp[n - 1].get(0).val() << endl;
}
