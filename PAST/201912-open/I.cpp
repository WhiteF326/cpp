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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<int> s(m);
    vector<ll> c(m);
    for(int i = 0; i < m; i++){
        string t; cin >> t;
        for(int j = 0; j < n; j++){
            if(t[j] == 'Y') s[i] += (1 << j);
        }
        cin >> c[i];
    }

    vector<ll> dp(1 << n, LLONG_MAX / 2);
    dp[0] = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        for(int i = 0; i < m; i++){
            chmin(dp[bit | s[i]], dp[bit] + c[i]);
        }
    }

    if(dp[(1 << n) - 1] == LLONG_MAX / 2) cout << -1 << endl;
    else cout << dp[(1 << n) - 1] << endl;
}
