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
    
    int n; cin >> n;
    string s; cin >> s;

    // 逆を考えたら無になった

    if(s[0] != 'R' || s[n - 1] != 'B'){
        cout << "No" << endl;
        return 0;
    }

    // RB と GG はだめ

    for(int i = 0; i < n - 1; i++){
        if(s.substr(i, 2) == "RB" || s.substr(i, 2) == "GG"){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}