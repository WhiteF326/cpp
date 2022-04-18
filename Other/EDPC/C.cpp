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
    
    int n; cin >> n;

    // i 日目で、直前の行動が j であるときの幸福度の最大値
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for(int i = 0; i < n; i++){
        vector<int> h(3);
        aryin(h, 3);
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j == k) continue;
                chmax(dp[i + 1][k], dp[i][j] + h[k]);
            }
        }
    }

    cout << *max_element(all(dp[n])) << endl;
}
