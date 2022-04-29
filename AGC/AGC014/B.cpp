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
    vector<int> a(n + 1, 0);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        a[x - 1]++;
        a[y - 1]--;
    }
    for(int i = 0; i < n; i++) a[i + 1] += a[i];
    bool ans = true;
    for(int v : a) if(v & 1) ans = false;

    cout << (ans ? "YES" : "NO") << endl;
}
