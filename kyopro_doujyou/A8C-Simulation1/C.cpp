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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a; cin >> a;

    if(a == 1){
        cout << 0 << endl;
        return 0;
    }

    int b; cin >> b;
    vector<ll> d(b + 2);
    d[0] = 0;
    for(int i = 0; i < b; i++) cin >> d[i + 1];
    d[b + 1] = n + 1;
    sort(all(d));
    
    ll ans = n - b;
    for(int i = 0; i < b + 1; i++){
        ll diff = d[i + 1] - d[i] - 1;
        ans -= diff / a;
    }
    cout << ans << endl;
}
