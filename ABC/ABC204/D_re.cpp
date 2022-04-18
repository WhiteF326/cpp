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

template<typename T>
T sum(const vector<T>& a){
    return accumulate(all(a), T());
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> t(n);
    aryin(t, n);

    int st = sum(t);

    vector<bitset<100001>> dp(n + 1, bitset<100001>(0));
    dp[0].set(0, 1);

    for(int i = 0; i < n; i++){
        dp[i + 1] |= dp[i];
        dp[i + 1] |= dp[i] << t[i];
    }

    int ans = INT_MAX;

    for(int i = 0; i <= 100000; i++){
        if(dp[n].test(i)){
            chmin(ans, max(abs(st - i), i));
        }
    }

    cout << ans << endl;
}
