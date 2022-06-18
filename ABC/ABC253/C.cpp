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
    
    int q; cin >> q;
    map<int, int> mp;

    query(q){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            mp[x]++;
        }else if(t == 2){
            int x, c; cin >> x >> c;
            if(mp[x] <= c){
                mp.erase(x);
            }else{
                mp[x] -= c;
            }
        }else{
            // t == 3
            int l = (*mp.begin()).first;
            int r = (*mp.rbegin()).first;
            cout << r - l << "\n";
        }
    }
    fflush(stdout);
}
