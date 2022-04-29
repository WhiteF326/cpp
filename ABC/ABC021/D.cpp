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
int n, k;
long long fac[200001], finv[200001], inv[200001];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 200001; i++){
        fac[i] = fac[i - 1] * i % modv;
        inv[i] = modv - inv[modv % i] * (modv / i) % modv;
        finv[i] = finv[i - 1] * inv[i] % modv;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % modv) % modv;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    COMinit();
    cout << COM(n + k - 1, k) << endl;
}
