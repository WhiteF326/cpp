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
    
    map<int, int> x, y;
    for(int i = 0; i < 3; i++){
        int a, b; cin >> a >> b;
        x[a]++;
        y[b]++;
    }

    int ax, ay;
    for(auto p : x){
        if(p.second == 1) ax = p.first;
    }
    for(auto p : y){
        if(p.second == 1) ay = p.first;
    }

    cout << ax << " " << ay << endl;
}
