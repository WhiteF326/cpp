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
    ll m; cin >> m;
    vector<ll> a(n);
    aryin(a, n);

    sort(all(a), greater<ll>());

    if(m == 1){
        cout << a[0] * 2 << endl;
        return 0;
    }

    vector<ll> b(all(a));
    for(int i = 1; i < n; i++) b[i] += b[i - 1];

    ll ans = a[0] * 2;
    m--;
    for(int i = 1; i < n; i++){
        ll res = 0;
        int dest = min(m / 2, (ll)i);
        if(dest){
            res = b[dest - 1] * 2 + a[i] * dest * 2;
            m -= dest * 2;
        }
        if(i > m / 2 && m % 2 == 1){
            res += b[dest] + a[i];
            m--;
        }
        ans += res;
        if(!m) break;
    }
    cout << ans << endl;
}
