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


ll sqrtint_binary(ll x){
    ll l = -1, r = 3000000001;
    while(r - 1 > l){
        ll m = l + (r - l) / 2;
        if(m * m > x){
            r = m;
        }else{
            l = m;
        }
    }
    return l;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans = 0;
    for(int i = 1; i <= 1000000; i++){
        ans += sqrtint_binary(i);
    }
    cout << ans << endl;
}