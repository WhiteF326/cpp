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
#define query(t) while (t--)
#define aryin(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)

#define mint modint1000000007

#define mtrx vector<vector<mint>>
mtrx mtrxMul(mtrx &a, mtrx &b) {
    mtrx res(a.size(), vector<mint>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
mtrx mtrxPow(mtrx a, ll n) {
    mtrx res(a.size(), vector<mint>(a.size()));
    for (int i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1)
            res = mtrxMul(a, res);
        a = mtrxMul(a, a);
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    ll k; cin >> k;

    mtrx pw(n, vector<mint>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            pw[i][j] = a;
        }
    }

    auto res = mtrxPow(pw, k);

    mint ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += res[i][j];
        }
    }
    cout << ans.val() << endl;
}
