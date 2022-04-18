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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<mint> dp(1 << n, 0);
    dp[0] = 1;

    vector<vector<int>> match(n, vector<int>(n, 0));
    for(int i = 0; i < n * n; i++){
        cin >> match[i / n][i % n];
    }

    for(int bit = 0; bit < (1 << n); bit++){
        int p = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)) p++;
        }
        for(int i = 0; i < n; i++){
            if((bit >> i & 1) && match[p - 1][i]){
                dp[bit] += dp[bit ^ (1 << i)];
            }
        }
    }

    cout << dp[(1 << n) - 1].val() << endl;
}
