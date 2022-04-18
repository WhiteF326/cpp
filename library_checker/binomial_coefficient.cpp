#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


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
        }else if(B == BinomType(Pascal)){
            pascal.resize(L);
            for(int i = 0; i < L; i++) pascal[i].resize(L);

            pascal[0][0] = 1;
            for(int i = 1; i < L; i++){
                pascal[i][0] = 1;
                for(int j = 1; j < L; j++){
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
                }
            }
        }else if(B == BinomType(AnyP)){
            // nothing to initialize
            pmod = n;
        }else{
            // not implemented
            exit(EXIT_FAILURE);
        }
    }

    void giveMod(int mod){
        pmod = mod;
    }

    S C(int n, int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        if(B == BinomType(Normal)){
            return S(fac[n] * (finv[k] * finv[n - k] % mod) % mod);
        }else if(B == BinomType(LargeN)){
            S ans = 1;
            for(int i = 1; i <= k; i++){
                ans = ans * ((n - i + 1) * inv[i] % mod) % mod;
            }
            return ans;
        }else if(B == BinomType(LargeNLocked)){
            return c_ans[k];
        }else if(B == BinomType(Pascal)){
            return pascal[n][k];
        }else if(B == BinomType(AnyP)){
            long long x = pmod;
            vector<long long> a, m;
            for(int i = 2; i <= pmod; i++){
                if(x % i == 0){
                    long long cnt = 0, pr = 1;
                    while(x % i == 0){
                        x /= i;
                        cnt++;
                        pr *= i;
                    }
                    makeFact(i, cnt);
                    a.push_back(C_sub(n, k, i, cnt));
                    m.push_back(pr);
                }
            }

            return crt(a, m).first;
        }else{
            // not implemented
            exit(EXIT_FAILURE);
        }
    }

    S C(int k){
        if(k < 0) return 0;
        if(B == BinomType(LargeNLocked)){
            return c_ans[k];
        }else{
            exit(EXIT_FAILURE);
        }
    }

    S C_sub(long long n, long long r, long long p, long long q){
        if(n < 0 || r < 0 || r > n) return 0;
        int pr = 1;
        for(int i = 0; i < q; i++) pr *= p;

        long long z = n - r;
        int e0 = 0;
        for(long long u = n / p; u; u /= p) e0 += u;
        for(long long u = r / p; u; u /= p) e0 -= u;
        for(long long u = z / p; u; u /= p) e0 -= u;
        
        int em = 0;
        for(long long u = n / pr; u; u /= p) em += u;
        for(long long u = r / pr; u; u /= p) em -= u;
        for(long long u = z / pr; u; u /= p) em -= u;
        
        S ret = 1;

        while(n > 0){
            ret = ret * fac[n % pr] % pr * finv[r % pr] * finv[z % pr] % pr;
            n /= p;
            r /= p;
            z /= p;
        }

        (ret *= binpow(p, e0, pr)) %= pr;

        if(!(p == 2 && q >= 3) && em % 2) ret = (pr - ret) % pr;
        return ret;
    }

    S H(int n, int k){
        if(B == BinomType(LargeNLocked)){
            exit(EXIT_FAILURE);
        }
        if(n < 0 || k < 0) return 0;
        return C(n + k - 1, k);
    }

    S P(int n, int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        if(B == BinomType(Normal)){
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
        if(k < 0) return 0;
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
    vector<vector<S>> pascal;

    int pmod;

    long long binpow(long long x, long long e, long long me){
        long long a = 1, p = x;
        while(e > 0){
            if(e%2 == 0){
                p = (p * p) % me;
                e /= 2;
            }else{
                a = (a * p) % me;
                e--;
            }
        }
        return a % me;
    }

    long long extgcd(long long a, long long b, long long &x, long long &y){
        long long g = a;
        x = 1, y = 0;
        if(b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
        return g;
    }

    long long inverse(long long a, long long n){
        long long s, t;
        extgcd(a, n, s, t);
        return (n + s) % n;
    }

    void makeFact(long long p, long long q){
        long long pr = 1;
        for(int i = 0; i < q; i++) pr *= p;

        fac.assign(pr + 1, 0);
        finv.assign(pr + 1, 0);
        fac[0] = finv[0] = 1;

        for(int i = 1; i <= pr; i++){
            if(i % p == 0){
                fac[i] = fac[i - 1];
            }else{
                fac[i] = fac[i - 1] * i % pr;
            }
            finv[i] = inverse(fac[i], pr);
        }
    }

    pair<long long, long long> crt(long long a1, long long a2, long long m1, long long m2){
        auto normal = [](long long x, long long m){
            return x >= -x ? x % m : m - (-x) % m;
        };
        auto modmul = [&normal](long long a, long long b, long long m){
            return normal(a, m) * normal(b, m) % m;
        };

        long long k1 = 0, k2 = 0;
        long long g = extgcd(m1, m2, k1, k2);
        if(normal(a1, g) != normal(a2, g)) return {-1, -1};

        long long l = m1 / g * m2;
        long long x = a1 + modmul(modmul((a2 - a1) / g, k1, l), m1, l);
        return {x, l};
    }

    pair<long long, long long> crt(vector<long long> a, vector<long long> m){
        long long me = 1, ans = 0;
        int n = a.size();

        for(int i = 0; i < n; i++){
            tie(ans, me) = crt(ans, a[i], me, m[i]);
            if(ans == -1) return {-1, -1};
        }

        return {ans, me};
    }
};

int main(){
    int t; cin >> t;
    int m; cin >> m;

    Binom<ll, 0, AnyP, 0> binom(m);
    query(t){
        ll n, k; cin >> n >> k;
        cout << binom.C(n, k) << "\n";
    }
}
