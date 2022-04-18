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
    
    int h, w; cin >> h >> w;
    vector<vector<bool>> stage(h, vector<bool>(w, 0));
    for(int i = 0; i < h; i++){
        string s; cin >> s;
        for(int j = 0; j < w; j++){
            if(s[j] == '.') stage[i][j] = 1;
        }
    }

    vector<vector<mint>> dp(h, vector<mint>(w, 0));
    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!stage[i][j]) continue;

            if(i < h - 1 && stage[i + 1][j]){
                dp[i + 1][j] += dp[i][j];
            }
            if(j < w - 1 && stage[i][j + 1]){
                dp[i][j + 1] += dp[i][j];
            }
        }
    }

    cout << dp[h - 1][w - 1].val() << endl;
}
