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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;
    vector<vector<int>> v(2, vector<int>(n, 0));
    aryin(v[0], n);
    aryin(v[1], n);

    // dp[i][j] = i 番目に j を選べるか？
    vector<vector<bool>> dp(n, vector<bool>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int e = 0; e < 2; e++){
                if(abs(v[j][i - 1] - v[e][i]) <= k){
                    dp[i][e] = (dp[i][e] | dp[i - 1][j]);
                }
            }
        }
    }

    cout << (dp[n - 1][0] || dp[n - 1][1] ? "Yes" : "No") << endl;
}
