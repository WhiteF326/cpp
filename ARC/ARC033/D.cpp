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


namespace shiroha{
    namespace math{
        /*
            与えられる点の x 座標が初項 a, 公差 d の等差数列である時、
            加えて y 座標を与えて、ラグランジュ補間を行い、x = t における y の値を求める。
        */
        template<typename T>
        T lagrange(T a, T d, vector<T> y, T t){
            const int n = y.size() - 1;
            T ret = 0, ft = 1;
            for(int i = 0; i <= n; i++) ft *= t - (a + d * i);
            T f = 1;
            for(int i = 1; i <= n; i++) f *= -1 * i * d;
            ret += y[0] / f * ft / (t - a);
            for(int i = 0; i < n; i++){
                f *= d * (i + 1) / (d * (i - n));
                ret += y[i + 1] / f * ft / (t - a - d * (i + 1));
            }
            return ret;
        }
    }
}

#define mint modint1000000007
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<mint> p(n + 1);
    for(int i = 0; i < n + 1; i++){
        int x; cin >> x;
        p[i] = x;
    }
    int t; cin >> t;

    cout << shiroha::math::lagrange<mint>(0, 1, p, t).val() << endl;
}
