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


int n;
int minop(int a, int b){
    return min(a, b);
}
int maxop(int a, int b){
    return max(a, b);
}
int me(){
    return 0;
}
int xe(){
    return n;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    segtree<int, maxop, me> lseg(100001);
    vector<int> init(100001, n);
    segtree<int, minop, xe> rseg(init);

    vector<int> w(n);
    aryin(w, n);
    vector<queue<int>> g(100001);
    for(int i = 0; i < n; i++){
        if(rseg.get(w[i]) == n) rseg.set(w[i], i);
        g[w[i]].push(i);
    }

    for(int i = 0; i < n; i++){
        cout << rseg.prod(w[i] + 1, 100001) - lseg.prod(w[i] + 1, 100001) - 1 << "\n";
        lseg.set(w[i], i + 1);
        g[w[i]].pop();
        if(!g[w[i]].empty()){
            rseg.set(w[i], g[w[i]].front());
        }else{
            rseg.set(w[i], n);
        }

        // for(int i = 0; i < n; i++){
        //     cout << lseg.get(i + 1) << " ";
        // }cout << endl;
        // for(int i = 0; i < n; i++){
        //     cout << rseg.get(i + 1) << " ";
        // }cout << endl;
    }
    fflush(stdout);
}
