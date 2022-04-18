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


int n;
ll a[401];
ll dp[401][401];

ll rev(int l, int r){
    if(l == r) return 0LL;
    if(dp[l][r]) return dp[l][r];

    ll res = 1LL<<60;
    for(int i = l; i < r; i++){
        chmin(res, rev(l, i) + rev(i + 1, r));
    }

    res += a[r];
    if(l > 0) res -= a[l - 1];
    return dp[l][r] = res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    aryin(a, n);

    for(int i = 1; i < n; i++) a[i] += a[i - 1];

    cout << rev(0, n - 1) << endl;
}
