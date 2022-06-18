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
    
    int n, m; cin >> n >> m;
    vector<ll> s(n - 1); aryin(s, n - 1);
    vector<ll> x(m); aryin(x, m);

    vector<ll> a(n, 0);
    for(int i = 1; i < n; i++) a[i] = s[i - 1] - a[i - 1];

    unordered_map<ll, int> ctr;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ctr[(x[j] - a[i]) / (i % 2 ? -1 : 1)]++;
        }
    }

    int ans = 0;
    for(auto p : ctr) chmax(ans, p.second);
    cout << ans << endl;
}
