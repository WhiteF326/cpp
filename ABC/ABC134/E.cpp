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
    vector<int> a(n);
    aryin(a, n);

    vector<int> lds(n, -1);
    for(int i = 0; i < n; i++){
        auto itr = lower_bound(all(lds), a[i], [&](const int& a, const int& b){
            return a >= b;
        });
        chmax(*itr, a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(lds[i] != -1) ans++;
    }
    cout << ans << endl;
}
