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


#define modv 998244353
#define mint modint998244353
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, l; cin >> n >> l;
    vector<string> s(n);
    aryin(s, n);

    mint ans = 0;
    for(int bit = 1; bit < (1 << n); bit++){
        int p = 0;
        vector<int> cnt(26, 0);
        for(int j = 0; j < n; j++){
            if(bit & (1 << j)){
                p++;
                for(char c : s[j]) cnt[c - 'a']++;
            }
        }

        int mx = 0;
        for(int v : cnt) mx += v / p;

        if(p % 2 == 0){
            ans -= mint(mx).pow(l);
        }else{
            ans += mint(mx).pow(l);
        }
    }

    cout << ans.val() << endl;
}
