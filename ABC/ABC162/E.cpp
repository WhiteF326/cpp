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


#define mint modint1000000007
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<mint> res(k + 1, 0);

    for(int i = 1; i <= k; i++){
        res[i] = mint(k / i).pow(n);
    }

    mint ans = 0;
    for(int i = k; i >= 1; i--){
        mint rev = res[i];
        for(int d = i * 2; d <= k; d += i){
            rev -= res[d];
        }
        // cout << rev.val() << endl;
        ans += rev * i;
        res[i] = rev;
    }
    cout << ans.val() << endl;
}
