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


struct Edge{
    int l, r;
    ll c;
};

bool operator< (const Edge& a, const Edge& b){
    return a.c < b.c;
}
bool operator> (const Edge& a, const Edge& b){
    return a.c > b.c;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for(int i = 0; i < n; i++){
        ll c; cin >> c;
        q.push({i, n, c});
    }
    for(int i = 0; i < m; i++){
        int a, b; ll c; cin >> a >> b >> c;
        a--, b--;
        q.push({a, b, c});
    }

    dsu d(n + 1);
    ll ans = 0;
    while(!q.empty()){
        Edge edge = q.top();
        q.pop();
        if(d.same(edge.l, edge.r)) continue;
        ans += edge.c;
        d.merge(edge.l, edge.r);
    }
    cout << ans << endl;
}