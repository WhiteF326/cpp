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
    
    int n, k; cin >> n >> k;
    vector<vector<int>> d(k);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        d[i % k].push_back(v);
    }
    for(int i = 0; i < k; i++) sort(all(d[i]));

    vector<int> res(n);
    for(int i = 0; i < n; i++){
        res[i] = d[i % k][i / k];
    }
    for(int i = 1; i < n; i++){
        if(res[i - 1] > res[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
