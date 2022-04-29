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

    int n, p; cin >> n >> p;
    vector<int> pl(p, 0);
    string s; cin >> s;
    vector<int> x(n);
    for(int i = 0; i < n; i++) x[i] = s[i] - '0';
    int d = 1;
    for(int i = 0; i < n; i++){
        x[n - 1 - i] = x[n - 1 - i] * d % p;
        d = d * 10 % p;
    }
    for(int i = 1; i < n; i++) x[i] = (x[i] + x[i - 1]) % p;
    for(int v : x) pl[v]++;

    ll ans = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        ans += pl[cur];
        pl[x[i]]--;
        cur = x[i];
    }
    cout << ans << endl;
}
