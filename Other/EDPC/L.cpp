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


ll infl = 1LL<<60;
vector<vector<ll>> dp(3001, vector<ll>(3001, infl));
vector<ll> a(3001, 0);
int n;
ll rev(int l, int r){
    if(l == r) return 0;

    if(dp[l][r] != infl) return dp[l][r];

    if((n - (r - l)) % 2 == 0){
        dp[l][r] = max(a[l] + rev(l + 1, r), rev(l, r - 1) + a[r - 1]);
    }else{
        dp[l][r] = min(-a[l] + rev(l + 1, r), rev(l, r - 1) - a[r - 1]);
    }

    return dp[l][r];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    aryin(a, n);

    rev(0, n);

    cout << dp[0][n] << endl;
}
