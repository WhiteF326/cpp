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
    int k; cin >> k;
    vector<int> h(n);
    aryin(h, n);

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i + j >= n) continue;
            chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[n - 1] << endl;
}
