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


const int infl = 1 << 30;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> dp(301, infl);
    dp[n] = 0;
    vector<int> a(301, 0);
    for(int i = 0; i < 3; i++){
        int v; cin >> v;
        a[v] = 1;
    }

    if(a[n] == 1){
        cout << "NO" << endl;
        return 0;
    }

    for(int i = n; i >= 0; i--){
        if(dp[i] == infl) continue;
        for(int d = 1; d <= 3; d++){
            if(i - d >= 0 && !a[i - d]){
                chmin(dp[i - d], dp[i] + 1);
            }
        }
    }

    if(dp[0] <= 100){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
