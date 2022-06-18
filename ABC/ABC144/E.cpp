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
    
    int n; cin >> n;
    ll k; cin >> k;

    vector<ll> a(n), f(n);
    aryin(a, n);
    aryin(f, n);

    sort(all(a));
    sort(all(f), greater<ll>());

    ll left = -1, right = 1LL << 60;
    while(right - left > 1){
        ll v = k;
        ll mid = left + (right - left) / 2;
        for(int i = 0; i < n; i++){
            v -= max(a[i] - mid / f[i], 0LL);
        }
        if(v >= 0) right = mid;
        else left = mid;
    }
    cout << right << endl;
}
