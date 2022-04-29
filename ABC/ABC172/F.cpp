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
    
    int n; cin >> n;
    vector<ll> a(n);
    aryin(a, n);

    ll v = 0;
    for(int i = 2; i < n; i++) v ^= a[i];

    ll d = 0, e = 1;
    // dp[i][j] = i 桁目まで作れていて carry = j であるパターンはあるか？
    vector<vector<ll>> dp(41, vector<ll>(2, 1LL << 60));
    dp[0][0] = 0;

    for(int i = 0; i < 40; i++){
        for(int j = 0; j <= 1; j++){
            int w = bool(a[0] & e) + bool((a[1] + dp[i][j]) & e);
            if((w & 1) == bool(v & e)){
                if(w + j >= 2 && dp[i][j] + e < a[0]){
                    chmin(dp[i + 1][1], dp[i][j] + e);
                    chmin(dp[i + 1][0], dp[i][j]);
                }else{
                    chmin(dp[i + 1][0], dp[i][j]);
                }
            }
        }
        e <<= 1;
    }

    if(dp[40][0] != 1LL << 60 || dp[40][1] != 1LL << 60){
        cout << min(dp[40][0], dp[40][1]) << endl;
    }else{
        cout << -1 << endl;
    }
}
