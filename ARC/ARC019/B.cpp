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
    
    string a; cin >> a;
    ll ans = 25LL * a.length();

    string l = a;
    string r = a;
    reverse(all(r));

    if(l == r){
        ans -= (a.length() % 2) * 25;
    }

    int diff = 0;
    for(int i = 0; i < l.length(); i++){
        if(l[i] != r[i]) diff++;
    }

    if(diff == 2){
        ans -= 2;
    }
    cout << ans << endl;
}
