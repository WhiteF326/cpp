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
    
    ll ans = 0;

    vector<int> spf(n + 1, 0);
    spf[1] = 1;
    for(int i = 2; i <= n; i++){
        if(spf[i]) continue;
        spf[i] = i;
        for(int j = i * 2; j <= n; j += i) spf[j] = i;
    }
    for(ll s = 1; s <= n; s++){
        ll v = s * s;
        for(int j = v / n; j <= n; j++){
            //
        }
    }
    cout << ans << endl;
}
