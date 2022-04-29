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
    vector<int> a(n);
    aryin(a, n);

    vector<ll> m(200001, 0);
    for(int v : a) m[v]++;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j * j <= a[i]; j++){
            if(a[i] % j) continue;
            if(j * j == a[i]){
                // A_j = A_k
                ans += m[j] * m[j];
            }else{
                ans += m[j] * m[a[i] / j] * 2;
            }
        }
    }

    cout << ans << endl;
}
