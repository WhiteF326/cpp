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


template<typename T>
struct Dijkstra {
    vector<T> depth;
    vector<int> from;
    Dijkstra() {}
    Dijkstra(vector<vector<pair<int, T>>>& g, int start = 0){
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
        q.push({T(0), start});

        depth.assign(g.size(), LLONG_MAX >> 2);
        depth[start] = 0;
        from.assign(g.size(), -1);

        while(!q.empty()){
            pair<T, int> dest = q.top();
            q.pop();

            for(pair<int, T> v : g[dest.second]){
                if(depth[v.first] > depth[dest.second] + v.second){
                    depth[v.first] = depth[dest.second] + v.second;
                    from[v.first] = dest.second;
                    q.push({depth[dest.second] + v.second, v.first});
                }
            }
        }
    }
    
    vector<T> distanceList(){
        return depth;
    }

    vector<int> getPath(int p){
        vector<int> ans;
        stack<int> st;
        while(from[p] != -1){
            st.push(p);
            p = from[p];
        }
        st.push(p);
        while(!st.empty()){
            ans.emplace_back(st.top());
            st.pop();
        }
        return ans;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; ll t; cin >> n >> m >> t;
    vector<ll> a(n);
    aryin(a, n);

    vector<vector<pair<int, ll>>> g(n), h(n);
    for(int i = 0; i < m; i++){
        int l, r, c; cin >> l >> r >> c;
        l--, r--;
        g[l].push_back({r, c});
        h[r].push_back({l, c});
    }

    vector<ll> gd = Dijkstra<ll>(g, 0).distanceList();
    vector<ll> hd = Dijkstra<ll>(h, 0).distanceList();

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(t < gd[i] + hd[i]) continue;
        chmax(ans, (t - gd[i] - hd[i]) * a[i]);
    }
    cout << ans << endl;
}
