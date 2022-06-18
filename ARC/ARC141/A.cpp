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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    query(t){
        string s; cin >> s;
        int n = s.length();

        string def = "";
        for(int i = 0; i < n - 1; i++) def += "9";
        ll ans = stoll(def);

        for(int i = n / 2; i >= 1; i--){
            if(n % i) continue;
            string t = s.substr(0, i);
            string est = "";
            for(int j = 0; j < n / i; j++) est += t;

            ll v = stoll(est);
            if(v > stoll(s)){
                t = to_string(stoll(t) - 1);
                est = "";
                for(int j = 0; j < n / i; j++) est += t;
                chmax(ans, stoll(est));
            }else{
                chmax(ans, v);
            }
        }
        cout << ans << endl;
    }
}
