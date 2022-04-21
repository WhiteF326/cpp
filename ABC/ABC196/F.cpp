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


#define mint modint998244353
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t; cin >> s >> t;
    reverse(all(t));
    int n = int(s.length()), m = t.length();
    vector<int> sl1(n), sl2(n), tl1(m), tl2(m);
    for(int i = 0; i < n; i++) sl1[i] = s[i] == '1', sl2[i] = s[i] != '1';
    for(int i = 0; i < m; i++) tl1[i] = t[i] == '1', tl2[i] = t[i] != '1';
    sl1 = convolution(sl1, tl2);
    sl2 = convolution(sl2, tl1);

    int ans = 1 << 30;
    for(int i = m - 1; i < n; i++){
        chmin(ans, int(sl1[i] + sl2[i]));
    }
    cout << ans << endl;
}