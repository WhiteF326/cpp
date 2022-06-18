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
    vector<ll> a(n); aryin(a, n);
    ll mx = *max_element(all(a));
    
    ll ans = 0;
    do{
        mx = 0;
        for(int i = 0; i < n; i++){
            ll t = a[i] / n;
            ans += t;
            a[i] -= t * n;
            chmax(mx, a[i]);
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                a[j] += t;
                chmax(mx, a[j]);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << a[i] << " ";
        // }cout << endl;
    }while(mx > n - 1);
    cout << ans << endl;
}
