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
    
    int q; cin >> q;
    query(q){
        ll a, b, c; cin >> a >> b >> c;
        ll t = (100 * a + 10 * b + c);
        if(t % 2){
            cout << "No" << endl;
        }else{
            t = (100 * a + 10 * b + c) / 2;
            t -= min(t / 100, a) * 100;
            t -= min(t / 10, b) * 10;
            t -= min(t, c);

            if(t == 0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
