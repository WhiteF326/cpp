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


const int MAX = 510000;
const int modv = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

void c_init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % modv;
        inv[i] = modv - inv[modv % i] * (modv / i) % modv;
        finv[i] = finv[i - 1] * inv[i] % modv;
    }
}

ll C(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % modv) % modv;
}

ll H(int n, int k){
    if(n == 0 && k == 0) return 1;
    return C(n + k - 1, k);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    c_init();
    
    int n, k; cin >> n >> k;

    if(k >= n){
        cout << H(n, n) << endl;
        return 0;
    }
    if(k == 1){
        cout << 1LL * n * (n - 1) % modv << endl;
    }else{
        ll ans = 0;
        for(int i = 0; i <= k; i++){
            ans += C(n, i) * H(n - i, i) % modv;
        }
        cout << ans % modv << endl;
    }
}