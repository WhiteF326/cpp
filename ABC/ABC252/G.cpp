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


#define modv 998244353
#define mint modint998244353
vector<int> p(500);
vector<vector<mint>> dp(501, vector<mint>(501, 0));
vector<vector<bool>> pt(501, vector<bool>(501, false));

// answer for [l : r)
mint vdp(int l, int r){
    if(pt[l][r]) return dp[l][r];
    mint ans = 0;

    if(r - l == 1) return 1;
    for(int i = l + 1; i < r - 1; i++){
        // 横に並べる
        if(p[i] < p[i + 1]){
            ans += vdp(l, i) + vdp(i, r);
        }
    }
    
    dp[l][r] = ans;
    pt[l][r] = true;

    cout << l << " " << r << " " << ans.val() << endl;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    aryin(p, n);

    cout << vdp(0, n).val() << endl;
}
