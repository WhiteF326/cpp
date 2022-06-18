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
    ll l; cin >> l;

    vector<ll> a(n);
    aryin(a, n);

    sort(all(a));
    ll ans = 0;

    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(ll v : a) q.push(v);
    if(l - accumulate(all(a), 0LL) > 0){
        q.push(l - accumulate(all(a), 0LL));
    }

    while(q.size() > 1){
        ll x = q.top();
        q.pop();
        ll y = q.top();
        q.pop();
        
        ans += x + y;
        q.push(x + y);
    }

    cout << ans << endl;
}
