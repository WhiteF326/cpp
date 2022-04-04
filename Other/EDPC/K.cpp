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
    
    int n, k; cin >> n >> k;
    vector<bool> dp(k + 1, 0);
    vector<int> a(n);
    aryin(a, n);

    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i - a[j] >= 0 && !dp[i - a[j]]){
                dp[i] = 1;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
}
