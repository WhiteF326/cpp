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
    int n = s.length();

    ll ans = 0;
    map<int, int> cnt;

    char d, e;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == d && d != e){
            ans += (n - i - 1) - cnt[s[i]];
            for(int j = 0; j < 26; j++){
                cnt[j + 'a'] = 0;
            }
            cnt[s[i]] = n - i - 1;
        }
        cnt[s[i]]++;
        e = d;
        d = s[i];
    }

    cout << ans << endl;
}
