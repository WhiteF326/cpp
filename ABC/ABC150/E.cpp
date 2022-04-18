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


#define modv 1000000007
#define mint modint1000000007
const int mx = 510000;
mint fac[mx], finv[mx], inv[mx];

void cominit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for(int i = 2; i < mx; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = modv - inv[modv % i] * (modv / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

mint C(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cominit();
    
    // 値が異なっている箇所の集合×そのような集合になる数列の組の個数
    // 集合の小さいほうから重みを付けてその集合の答えにする

    // C(全体の個数, 選ぶ個数)
    cout << C(5, 2).val() << endl;
}
