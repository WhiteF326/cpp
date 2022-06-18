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
    vector<int> c(n);
    aryin(c, n);

    int odd = 0, mo = INT_MAX;
    int all = 0, ma = INT_MAX;
    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) chmin(mo, c[i]);
        chmin(ma, c[i]);
    }

    int q; cin >> q;
    query(q){
        int t; cin >> t;
        if(t == 1){
            int x, a; cin >> x >> a;
            x--;
            if(x & 1){
                int cur = c[x] - all;
                cout << cur << endl;
                if(cur >= a){
                    c[x] -= a;
                    ans += a;
                }
            }else{
                int cur = c[x] - odd - all;
                cout << cur << endl;
                if(cur >= a){
                    c[x] -= a;
                    ans += a;
                    chmin(mo, c[x]);
                }
            }
            chmin(ma, c[x]);
        }else if(t == 2){
            int a; cin >> a;
            if(mo - odd - all >= a){
                odd += a;
                ans += ll(a) * (n / 2 + (n & 1));
            }
        }else if(t == 3){
            int a; cin >> a;
            if(ma - all >= a){
                all += a;
                ans += ll(a) * n;
            }
        }
        // cout << odd << " " << all << endl;
        // for(int v : c) cout << v << " ";
        // cout << endl;
    }
    cout << ans << endl;
}
