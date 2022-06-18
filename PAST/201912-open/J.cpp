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


vector<vector<int>> vect = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w; cin >> h >> w;
    vector<vector<ll>> g(h, vector<ll>(w));
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> g[i][j];

    auto pos = [&](int x, int y){
        return x * h + y;
    };
    auto repos = [&](int pos){
        return pair<int, int>(pos / h, pos % h);
    };
    auto dijkstra = [&](int start){
        vector<vector<ll>> dist(h, vector<ll>(w, LLONG_MAX >> 1));
        dist[start / h][start % h] = 0;
        vector<vector<int>> path(h, vector<int>(w, -1));
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
        q.push({0, start});

        while(!q.empty()){
            ll d = q.top().first;
            int dest = q.top().second;
            q.pop();
            int cx, cy;
            tie(cx, cy) = repos(dest);

            for(int i = 0; i < 4; i++){
                int dx = cx + vect[i][0], dy = cy + vect[i][1];
                if(dx < 0 || dx >= h || dy < 0 || dy >= w) continue;

                int next = pos(dx, dy);
                if(dist[dx][dy] > dist[cx][cy] + g[dx][dy]){
                    dist[dx][dy] = dist[cx][cy] + g[dx][dy];
                    path[dx][dy] = dest;
                    if(g[dx][dy] == 0) continue;
                    q.push({dist[dx][dy], next});
                }
            }
        }

        return pair<vector<vector<ll>>, vector<vector<int>>>(dist, path);
    };

    // s -> t
    vector<vector<ll>> rdist;
    vector<vector<int>> rpath;
    tie(rdist, rpath) = dijkstra(pos(h - 1, 0));

    vector<vector<bool>> paths(h, vector<bool>(w, 0));
    paths[h - 1][w - 1] = 1;
    int curh = h - 1, curw = w - 1;
    while(rpath[curh][curw] != -1){
        tie(curh, curw) = repos(rpath[curh][curw]);
        paths[curh][curw] = 1;
    }

    // t -> s
    vector<vector<ll>> ldist = dijkstra(pos(h - 1, w - 1)).first;

    // u -> (path s -> t)
    ll ans = LLONG_MAX;
    vector<vector<ll>> hdist = dijkstra(pos(0, w - 1)).first;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!paths[i][j]) continue;
            chmin(ans, rdist[h - 1][w - 1] + ldist[i][j] + hdist[i][j]);
        }
    }

    cout << ans << endl;
}
