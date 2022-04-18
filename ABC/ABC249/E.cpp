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
    
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    aryin(a, n);

    // [y : x] のみを含み、かつ x, y のいずれをも含む

    vector<int> xlist(n + 1, n), ylist(n + 1, n);
    vector<int> outs(n + 1, n);
    for(int i = n - 1; i >= 0; i--){
        xlist[i] = xlist[i + 1];
        if(a[i] == x) xlist[i] = i;
        ylist[i] = ylist[i + 1];
        if(a[i] == y) ylist[i] = i;
        outs[i] = outs[i + 1];
        if(a[i] < y || a[i] > x) outs[i] = i;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int inc = max(xlist[i], ylist[i]);
        if(outs[i] < inc) continue;

        ans += outs[i] - inc;
    }
    cout << ans << endl;
}
