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
    
    int n; cin >> n;
    n %= 30;
    vector<int> p(6, 0);
    iota(all(p), 1);
    for(int i = 0; i < n; i++){
        swap(p[(i % 5)], p[(i % 5) + 1]);
    }
    for(int v : p) cout << v;
    cout << endl;
}
