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

ll bitpow(ll x, ll n){
    ll ans = 1;
    while(n > 0){
        if(n & 1) ans = ans * x % modv;
        x = x * x % modv;
        n >>= 1;
    }
    return ans;
}

enum BinomType{
    Normal,
    LargeN,
    LargeNLocked,
    Pascal,
    AnyP
};

template<typename S, int L, BinomType B, int mod>
class Binom{
public:
    Binom(int n = 1000000000){
        if(B == BinomType(Normal)){
            fac.assign(L, 0);
            finv.assign(L, 0);
            inv.assign(L, 0);

            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;

            for(int i = 2; i < L; i++){
                fac[i] = fac[i - 1] * i % mod;
                inv[i] = mod - inv[mod % i] * (mod / i) % mod;
                finv[i] = finv[i - 1] * inv[i] % mod;
            }
        }else if(B == BinomType(LargeN)){
            inv.assign(L, 0);
            inv[1] = 1;
            for(int i = 2; i < L; i++){
                inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            }
        }else if(B == BinomType(LargeNLocked)){
            inv.assign(L, 0);
            inv[1] = 1;
            for(int i = 2; i < L; i++){
                inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            }

            c_ans.assign(L, 0);
            c_ans[1] = n;
            for(int i = 2; i < L; i++){
                c_ans[i] = c_ans[i - 1] * ((n - i + 1) * inv[i] % mod) % mod;
            }

            p_ans.assign(L, 0);
            p_ans[1] = n;
            for(int i = 2; i < L; i++){
                p_ans[i] = p_ans[i - 1] * (n - i + 1) % mod;
            }
        }else{
            // not implemented
            exit(EXIT_FAILURE);
        }
    }

    S C(int n, int k){
        if(B == BinomType(Normal)){
            if(n < k) return 0;
            if(n < 0 || k < 0) return 0;
            return S(fac[n] * (finv[k] * finv[n - k] % mod) % mod);
        }else if(B == BinomType(LargeN)){
            S ans = 1;
            for(int i = 1; i <= k; i++){
                ans = ans * ((n - i + 1) * inv[i] % mod) % mod;
            }
            return ans;
        }else if(B == BinomType(LargeNLocked)){
            return c_ans[k];
        }else{
            // not implemented
            exit(EXIT_FAILURE);
        }
    }

    S C(int k){
        if(B == BinomType(LargeNLocked)){
            return c_ans[k];
        }else{
            exit(EXIT_FAILURE);
        }
    }

    S H(int n, int k){
        if(B == BinomType(LargeNLocked)){
            exit(EXIT_FAILURE);
        }
        if(n < 0 || k < 0) return 0;
        return C(n + k - 1, k);
    }

    S P(int n, int k){
        if(B == BinomType(Normal)){
            if(n < k) return 0;
            if(n < 0 || k < 0) return 0;
            return S(fac[n] * finv[n - k] % mod);
        }else if(B == BinomType(LargeN)){
            S ans = 1;
            for(int i = 1; i <= k; i++){
                ans = ans * (n - i + 1) % mod;
            }
            return ans;
        }else if(B == BinomType(LargeNLocked)){
            return p_ans[k];
        }else{
            // not implemented
            exit(EXIT_FAILURE);
        }
    }

    S P(int k){
        if(B == BinomType(LargeNLocked)){
            return p_ans[k];
        }else{
            exit(EXIT_FAILURE);
        }
    }

private:
    vector<S> fac;
    vector<S> finv;
    vector<S> inv;
    vector<S> c_ans, p_ans;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, a, b; cin >> n >> a >> b;
    Binom<ll, 200010, LargeNLocked, modv> binom(n);

    mint ans = bitpow(2, n) - 1;
    ans -= binom.C(a);
    ans -= binom.C(b);

    cout << ans.val() << endl;
}
