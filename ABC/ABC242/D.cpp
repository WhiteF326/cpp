#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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
    
    string s; cin >> s;
    int q; cin >> q;

    query(q){
        ll t, k; cin >> t >> k;
        k--;
        int d;
        if(t >= 63){
            d = 0;
        }else{
            d = k >> t;
        }

        int ans = (s[d] - 'A');
        ans = (ans + (t % 3)) % 3;
        if(d){
            k -= d * (1LL << t);
        }

        while(k){
            if(k & 1){
                ans = (ans + 1) % 3;
            }
            k >>= 1;
        }

        cout << (char)('A' + ans) << "\n";
    }
    fflush(stdout);
}
