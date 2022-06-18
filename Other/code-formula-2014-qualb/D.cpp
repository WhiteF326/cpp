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


#define modv 1000000007
#define mint modint1000000007
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<mint> a(n);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        a[i] = v;
    }

    // dp[i][j][k] = i 桁目まで決めていて i 桁目が j で実質 k 枚余っている
    mint dp[n + 1][10][10001];
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= 5000; k++){
                //
            }
        }
    }
}
