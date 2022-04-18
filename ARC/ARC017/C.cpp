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

    int n, x; cin >> n >> x;
    vector<int> w(n);
    aryin(w, n);

    auto blx = [](vector<int> &v){
        int s = v.size();
        // vector<int> d(1 << s);
        map<int, int> d;
        for(int bit = 0; bit < (1 << s); bit++){
            int res = 0;
            for(int i = 0; i < s; i++){
                if(bit & (1 << i)) res += v[i];
            }
            d[res]++;
        }
        return d;
    };

    vector<int> wl(n / 2, 0);
    for(int i = 0; i < n / 2; i++) wl[i] = w[i];
    // vector<int> wlv = blx(wl);
    map<int, int> wlv = blx(wl);
    vector<int> wr(n / 2 + (n & 1), 0);
    for(int i = 0; i < n / 2 + (n & 1); i++) wr[i] = w[n / 2 + i];
    map<int, int> wrv = blx(wr);

    // for(auto v : wr) print(v);

    ll ans = 0;
    for(auto p : wlv){
        ans += wrv[x - p.first] * p.second;
    }
    cout << ans << endl;
}