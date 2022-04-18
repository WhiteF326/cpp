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
    
    // 初期スコア + 反転区間の 0 - 反転区間の 1
    int n; cin >> n;

    vector<int> a(n);
    aryin(a, n);

    int mn = 0, mx = 0, cur = 0;
    int x = 0, y = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == 0) cur--;
        else cur++;

        chmin(x, cur - mx);
        chmax(y, cur - mn);
        chmin(mn, cur);
        chmax(mx, cur);
    }

    cout << y - x + 1 << endl;
}
