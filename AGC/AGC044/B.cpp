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
    
    ll h, w; cin >> h >> w;
    int n; cin >> n;

    auto trp = [&](ll a, ll b){
        return a * w + b;
    };

    unordered_map<ll, int> m;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        a--, b--;
        for(int x = -1; x <= 1; x++){
            for(int y = -1; y <= 1; y++){
                if(a + x < 1 || a + x >= h - 1 || b + y < 1 || b + y >= w - 1) continue;
                m[trp(a + x, b + y)]++;
            }
        }
    }

    ll trl = (h - 2) * (w - 2) - m.size();
    vector<int> ctr(10, 0);
    for(auto v : m){
        // cout << v.first / w << " " << v.first % w << endl;
        ctr[v.second]++;
    }
    cout << trl << endl;
    for(int i = 0; i < 9; i++) cout << ctr[i + 1] << endl;
}
