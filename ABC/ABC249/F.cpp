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


#define modv 998244353
#define mint modint998244353
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> p(n), q(n);
    aryin(p, n);
    aryin(q, n);

    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++){
        g[p[i] - 1].push_back(q[i] - 1);
        g[q[i] - 1].push_back(p[i] - 1);
    }

    dsu d(n);
    for(int i = 0; i < n; i++){
        d.merge(p[i] - 1, q[i] - 1);
    }

    mint ans = 1;
    // vector<bool> fd(n, false);
    for(auto g : d.groups()){
        if(g.size() != 1) ans *= (g.size() + 1);
    }
    cout << ans.val() << endl;
}
