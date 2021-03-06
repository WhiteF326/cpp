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


// unordered_map<ll, ll> mem;
vector<ll> mem(70000, 0);

ll sqrtint_binary(ll x){
    ll l = -1, r = 3000000001;
    while(r - 1 > l){
        ll m = l + ((r - l) >> 1);
        if(m * m > x){
            r = m;
        }else{
            l = m;
        }
    }
    return l;
}

ll dp(ll x, bool flg){
    if(x == 1) return 1;
    ll s = sqrtl(x);
    if(flg && mem[s] != 0){
        return mem[s];
    }
    ll v = 1, res = 0;
    while(v * v * v * v <= x){
        ll d = min(s + 1, (v + 1) * (v + 1)) - v * v;
        res += d * dp(v * v, true);
        v++;
    }
    if(flg) mem[s] = res;
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    query(t){
        ll x; cin >> x;
        cout << dp(x, false) << endl;
    }
}