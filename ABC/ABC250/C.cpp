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
    vector<int> a(n);
    iota(all(a), 0);
    vector<int> b(n);
    iota(all(b), 1);

    query(q){
        int x; cin >> x;
        x--;

        int sp = a[x];
        if(sp == n - 1){
            swap(b[n - 1], b[n - 2]);
            a[b[n - 1] - 1] = n - 1;
            a[b[n - 2] - 1] = n - 2;
        }else{
            swap(b[sp], b[sp + 1]);
            a[b[sp] - 1] = sp;
            a[b[sp + 1] - 1] = sp + 1;
        }
    }

    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }cout << endl;
}
