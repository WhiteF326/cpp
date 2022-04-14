#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

/*
# b[n] = ノードnからの流出先ノードの集合のbitフラグ
 
dp = [0] * (1 << N)
dp[0] = 1
# ノードIDと対応するビット位置は繰り返し求めるので事前計算しておく
jbs = [(j, 1 << j) for j in range(N)]
 
for i in range(1 << N):
    for j, jb in jbs:
        if (i & jb) == 0 and (i & b[j]) == 0:
            dp[i | jb] += dp[i]
 
print(dp[-1])
*/

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> g(n, 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a - 1] |= (1 << (b - 1));
    }

    vector<ll> dp(1 << n);
    dp[0] = 1;
    
    for(int bit = 0; bit < (1 << n); bit++){
        for(int i = 0; i < n; i++){
            if(!(bit & (1 << i)) && !(bit & g[i])){
                dp[bit | (1 << i)] += dp[bit];
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
