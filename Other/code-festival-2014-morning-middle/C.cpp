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


long long gcd(long long a, long long b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(a == 0) return b;
    if(b == 0) return a;
    if(a == 1 || b == 1) return 1;
    if(a == b) return a;
    return gcd(b, a % b);
}
class Fraction{
public:
    Fraction(){
        Fraction(0, 1);
    }
    Fraction(long long n, long long d){
        assert(d != 0);
        if(d < 0){
            n = -n;
            d = -d;
        }
        long long g = gcd(n, d);
        this->n = n / g;
        this->d = d / g;
    }

    long long n;
    long long d;
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.n * rhs.d + rhs.n * lhs.d, lhs.d * rhs.d);
}
Fraction operator-(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.n * rhs.d - rhs.n * lhs.d, lhs.d * rhs.d);
}
Fraction operator*(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.n * rhs.n, lhs.d * rhs.d);
}
Fraction operator/(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.n * rhs.d, lhs.d * rhs.n);
}
bool operator==(const Fraction& lhs, const Fraction& rhs){
    return lhs.n == rhs.n && lhs.d == rhs.d;
}
bool operator!=(const Fraction& lhs, const Fraction& rhs){
    return !(lhs == rhs);
}
bool operator<(const Fraction& lhs, const Fraction& rhs){
    return lhs.n * rhs.d < rhs.n * lhs.d;
}
bool operator>(const Fraction& lhs, const Fraction& rhs){
    return rhs < lhs;
}
bool operator<=(const Fraction& lhs, const Fraction& rhs){
    return !(lhs > rhs);
}
bool operator>=(const Fraction& lhs, const Fraction& rhs){
    return !(lhs < rhs);
}
Fraction operator-(const Fraction& rhs){
    return Fraction(-rhs.n, rhs.d);
}
Fraction operator+(const Fraction& rhs){
    return rhs;
}
Fraction operator++(Fraction& lhs){
    return lhs = Fraction(lhs.n + lhs.d, lhs.d);
}
Fraction operator--(Fraction& lhs){
    return lhs = Fraction(lhs.n - lhs.d, lhs.d);
}
Fraction operator++(Fraction& lhs, int){
    Fraction ret = lhs;
    lhs = Fraction(lhs.n + lhs.d, lhs.d);
    return ret;
}
Fraction operator--(Fraction& lhs, int){
    Fraction ret = lhs;
    lhs = Fraction(lhs.n - lhs.d, lhs.d);
    return ret;
}


#define mtrx vector<vector<ld>>
mtrx mtrxMul(mtrx &a, mtrx &b) {
    mtrx res(a.size(), vector<ld>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < b.size(); k++){
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}
mtrx mtrxPow(mtrx a, ll n){
    mtrx res(a.size(), vector<ld>(a.size()));
    for(int i = 0; i < a.size(); i++){
        res[i][i] = 1;
    }
    while(n > 0){
        if(n & 1) res = mtrxMul(a, res);
        a = mtrxMul(a, a);
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ld p; ll n; cin >> p >> n;
    cout << fs(12) << 0.5 * (1 - pow(1 - 2 * p, n)) << endl;
}
