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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    aryin(a, n);

    vector<ll> b(all(a));

    for(int i = 1; i < n; i++) b[i] += b[i - 1];
    map<ll, int> p;
    for(ll v : b) p[v % m]++;

    ll ans = 0, res = 0;
    for(int i = 0; i < n; i++){
        ans += p[res];
        res = (res + a[i]) % m;
        p[b[i] % m]--;
    }
    cout << ans << endl;
}
