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


enum pos {
    left, center, right
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w; cin >> h >> w;
    auto getPos = [&](int v, int c){
        return v * h + c;
    };
    vector<vector<pair<int, int>>> g(h * 3 + 3);
    vector<pair<int, int>> dl(h);
    for(int i = 0; i < h; i++){
        int a, b; cin >> a >> b;
        dl[getPos(i, pos::left)] = {1, a};
        dl[getPos(i, pos::center)] = {a, b};
        dl[getPos(i, pos::right)] = {b, w};
    }

    for(int i = 0; i < h - 1; i++){
        
    }
}
