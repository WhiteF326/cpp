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

    int n; cin >> n;
    vector<ll> a(n), b(n);
    aryin(a, n);
    aryin(b, n);

    vector<int> bits(63, 0);
    for(int i = 0; i < 63; i++){
        for(ll v : b) if(v & (1LL << i)) bits[i]++;
    }

    ll ans = 0;
    for(ll v : a){
        int carry = 0;
        ll res = 0;
        for(int i = 0; i < 63; i++){
            if(v & (1LL << i)){
                // 1
            }else{
                // 0
                res += (1LL << i) * ((bits[i] + carry) & 1);
            }
        }
    }
}
