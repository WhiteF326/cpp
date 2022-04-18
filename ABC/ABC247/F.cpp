#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define mint modint998244353
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> p(n), q(n);
    aryin(p, n);
    aryin(q, n);

    vector<mint> lucas(n + 3, 0);
    lucas[0] = 2, lucas[1] = 1, lucas[2] = 3;
    for(int i = 3; i <= n + 2; i++){
        lucas[i] = lucas[i - 1] + lucas[i - 2];
    }

    dsu d(n);
    for(int i = 0; i < n; i++){
        d.merge(p[i] - 1, q[i] - 1);
    }

    mint ans = 1;
    for(auto g : d.groups()){
        ans *= lucas[g.size()];
    }
    cout << ans.val() << endl;
}