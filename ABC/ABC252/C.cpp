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

    vector<string> s(n);
    aryin(s, n);

    vector<vector<int>> app(10, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++) app[s[i][j] - '0'][i] = j;
    }

    int ans = INT_MAX;
    for(int i = 0; i <= 9; i++){
        int res = 0;
        vector<int> count(10, 0);
        for(int v : app[i]) count[v]++;
        for(int j = 0; j < 10; j++){
            if(!count[j]) continue;
            chmax(res, j + (count[j] - 1) * 10);
        }
        chmin(ans, res);
    }
    cout << ans << endl;
}
