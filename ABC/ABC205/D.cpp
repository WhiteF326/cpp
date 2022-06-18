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
    
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    aryin(a, n);

    vector<ll> b(n, 0);
    b[0] = a[0] - 1;
    for(int i = 0; i < n - 1; i++){
        b[i + 1] = a[i + 1] - a[i] - 1;
    }
    for(int i = 1; i < n; i++){
        b[i] += b[i - 1];
    }

    query(q){
        ll k; cin >> k;
        int p = lower_bound(all(b), k) - b.begin();

        if(p == 0){
            cout << k << "\n";
        }else{
            ll d = k - b[p - 1];
            cout << a[p - 1] + d << "\n";
        }
    }
    fflush(stdout);
}
