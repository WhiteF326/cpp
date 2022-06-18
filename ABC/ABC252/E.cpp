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


struct Edge{
    int dest, c, no;
};
struct qv{
    ll first, second, no;
};

bool operator< (const qv& left, const qv& right){
    return left.first < right.first;
}
bool operator> (const qv& left, const qv& right){
    return left.first > right.first;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;

    vector<vector<Edge>> v(m);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b, c, i});
        v[b].push_back({a, c, i});
    }

    vector<ll> dist(n, INT_MAX);
    dist[0] = 0;
    vector<bool> visited(n, 0);
    visited[0] = 1;

    set<int> st;
    priority_queue<qv, vector<qv>, greater<qv>> q;
    for(auto e : v[0]){
        q.push({e.c, e.dest, e.no});
    }

    while(!q.empty()){
        ll dist = q.top().first;
        int dest = q.top().second;
        int no = q.top().no;
        q.pop();

        if(visited[dest]) continue;
        visited[dest] = 1;
        st.insert(no);

        for(auto e : v[dest]){
            if(visited[e.dest]) continue;
            q.push({dist + e.c, e.dest, e.no});
        }
    }

    for(int v : st) cout << v + 1 << " ";
    cout << endl;
}
