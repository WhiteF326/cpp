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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, d; cin >> n >> m >> d;
    vector<int> a(m);
    aryin(a, m);

    vector<int> u(n);
    iota(all(u), 0);
    for(int s : a) swap(u[s - 1], u[s]);

    vector<vector<int>> v(31, vector<int>(n));
    for(int i = 0; i < n; i++) v[0][u[i]] = i;

    for(int i = 0; i < 29; i++){
        for(int j = 0; j < n; j++){
            v[i + 1][j] = v[i][v[i][j]];
        }
    }

    for(int i = 0; i < n; i++){
        int sd = d;
        int ans = i;
        for(int j = 0; sd > 0; j++){
            if(sd & 1) ans = v[j][ans];
            sd >>= 1;
        }
        cout << ans + 1 << "\n";
    }
}
