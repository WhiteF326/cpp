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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll x, a, d, n; cin >> x >> a >> d >> n;

    if(d == 0){
        cout << abs(x - a) << endl;
        return 0;
    }

    ll s = (x - a) / d;

    if(s < 0 || s >= n){
        cout << min(abs(a - x), abs(a + (n - 1) * d - x)) << endl;
    }else if(s == n - 1){
        ll r = s * d + a;
        cout << abs(r - x) << endl;
    }else{
        ll r = s * d + a;
        cout << min(abs(r - x), abs(r + d - x)) << endl;
    }
}
