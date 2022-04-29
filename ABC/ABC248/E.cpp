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
    
    int n, k; cin >> n >> k;
    set<pair<double, double>> st;
    set<int> xl, yl;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    if(k == 1){
        cout << "Infinity" << endl;
        return 0;
    }

    // x = ?
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(x[i] == x[j]){
                sum++;
            }
        }
        if(sum >= k){
            xl.insert(x[i]);
        }
    }
    // y = ?
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(y[i] == y[j]){
                sum++;
            }
        }
        if(sum >= k){
            yl.insert(y[i]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            if(dx == 0 || dy == 0){
                continue;
            }

            int res = 0;
            for(int v = 0; v < n; v++){
                ll dx2 = x[i] - x[v];
                ll dy2 = y[i] - y[v];
                if(dx2 * dy == dy2 * dx){
                    res++;
                }
            }

            if(res >= k){
                double a = double(dy) / dx;
                double b = y[i] - a * x[i];
                st.insert({a, b});
            }
        }
    }

    cout << st.size() + xl.size() + yl.size() << endl;
}
