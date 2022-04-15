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

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int t, v; cin >> t >> v;
    double lim = t * v;

    int n; cin >> n;
    query(n){
        int x, y; cin >> x >> y;
        double dist = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
        dist += sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        if(dist <= lim){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
