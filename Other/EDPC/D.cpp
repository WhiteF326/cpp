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


const ll infl = 1LL << 60;
struct Item{
    ll w, v;
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, w; cin >> n >> w;
    vector<Item> t(n);
    for(int i = 0; i < n; i++){
        ll ww, v; cin >> ww >> v;
        t[i] = {ww, v};
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -infl));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            if(dp[i][j] == -infl) continue;
            chmax(dp[i + 1][j], dp[i][j]);
            if(j + t[i].w <= w){
                chmax(dp[i + 1][j + t[i].w], dp[i][j] + t[i].v);
            }
        }
    }

    cout << *max_element(all(dp[n])) << endl;
}
