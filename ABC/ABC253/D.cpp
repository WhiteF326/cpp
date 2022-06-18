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


ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, a, b; cin >> n >> a >> b;
    ll c = lcm(a, b);

    ll ans = n * (n + 1) / 2;
    ans -= (n / a * (n / a + 1) / 2) * a;
    ans -= (n / b * (n / b + 1) / 2) * b;
    ans += (n / c * (n / c + 1) / 2) * c;
    
    cout << ans << endl;
}
