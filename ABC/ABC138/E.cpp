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
    
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    ll ans = 0, cur = 0;
    vector<vector<int>> espr(n + 1, vector<int>(26, n));
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 26; j++) espr[i][j] = espr[i + 1][j];
        espr[i][s[i] - 'a'] = i;
    }

    for(int i = 0; i < m; i++){
        if(espr[0][t[i] - 'a'] == n){
            cout << -1 << endl;
            return 0;
        }
        if(espr[cur][t[i] - 'a'] == n){
            cur = 0;
            ans += n;
        }
        cur = espr[cur][t[i] - 'a'] + 1;
    }
    cout << ans + cur << endl;
}
