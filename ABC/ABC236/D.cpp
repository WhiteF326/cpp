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


// 最も小さい bit であって 0 であるものの場所を 0-indexed で返す。
int leftmost(int d){
    int pos = 0;
    while(d & 1) d >>= 1, pos++;
    return pos;
};

int n;
int v[16][16];
int ans = 0;

void rev(int bit, int depth, int cur = 0){
    if(depth == n){
        chmax(ans, cur);
        return;
    }
    int l = leftmost(bit);
    for(int i = l + 1; i < n * 2; i++){
        if(bit & (1 << i)) continue;
        rev(bit | (1 << l) | (1 << i), depth + 1, cur ^ v[l][i]);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    
    for(int i = 0; i < n * 2; i++){
        for(int j = i + 1; j < n * 2; j++){
            cin >> v[i][j];
        }
    }

    rev(0, 0);

    cout << ans << endl;
}
