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
    
    int n, q; cin >> n >> q;
    vector<vector<bool>> f(n, vector<bool>(n, 0));

    query(q){
        int t; cin >> t;
        if(t == 1){
            int a, b; cin >> a >> b;
            f[a - 1][b - 1] = 1;
        }else if(t == 2){
            int a; cin >> a;
            for(int i = 0; i < n; i++){
                if(f[i][a - 1]) f[a - 1][i] = 1;
            }
        }else{
            int a; cin >> a;
            set<int> st;
            for(int i = 0; i < n; i++){
                if(f[a - 1][i]) st.insert(i);
            }
            for(int i : st){
                if(!f[a - 1][i]) continue;
                for(int j = 0; j < n; j++){
                    if(f[i][j] && j != a - 1) f[a - 1][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (f[i][j] ? "Y" : "N");
        }cout << "\n";
    }
    fflush(stdout);
}
