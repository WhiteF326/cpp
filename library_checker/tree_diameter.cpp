#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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


namespace shiroha {
    namespace tree {
        struct BFS {
            vector<bool> visited;
            vector<int> depth;
            vector<int> from;
            BFS() {}
            BFS(vector<vector<int>>& g, int start = 0){
                queue<int> q;
                q.push(start);

                visited.assign(g.size(), 0);
                visited[start] = 1;
                depth.assign(g.size(), 0);
                from.assign(g.size(), -1);

                while(!q.empty()){
                    int dest = q.front();
                    q.pop();

                    for(const int& v : g[dest]){
                        if(visited[v]) continue;
                        visited[v] = true;
                        depth[v] = depth[dest] + 1;
                        from[v] = dest;
                        q.push(v);
                    }
                }
            }

            bool reachable(int p){
                return visited[p];
            }
            vector<int> distanceList(){
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

        struct Dijkstra {
            vector<long long> depth;
            vector<int> from;
            Dijkstra() {}
            Dijkstra(vector<vector<pair<int, long long>>>& g, int start = 0){
                priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
                q.push({0LL, start});

                depth.assign(g.size(), LLONG_MAX >> 1);
                depth[start] = 0;
                from.assign(g.size(), -1);

                while(!q.empty()){
                    pair<long long, int> dest = q.top();
                    q.pop();

                    for(pair<int, long long> v : g[dest.second]){
                        if(depth[v.first] > depth[dest.second] + v.second){
                            depth[v.first] = depth[dest.second] + v.second;
                            from[v.first] = dest.second;
                            q.push({depth[dest.second] + v.second, v.first});
                        }
                    }
                }
            }
            
            vector<long long> distanceList(){
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

        class Diameter {
        public:
            Diameter(vector<vector<int>>& g){
                BFS bfs1(g, 0);
                vector<int> d = bfs1.distanceList();
                int p = max_element(d.begin(), d.end()) - d.begin();
                bfs2 = BFS(g, p);

                e = bfs2.distanceList();
            }

            int get(){
                return *max_element(e.begin(), e.end());
            }

            vector<int> path(){
                return bfs2.getPath(max_element(e.begin(), e.end()) - e.begin());
            }

        private:
            vector<int> e;
            BFS bfs2;
        };

        class WeightedDiameter {
        public:
            WeightedDiameter(vector<vector<pair<int, long long>>>& g){
                Dijkstra dijkstra1(g, 0);
                vector<long long> d = dijkstra1.distanceList();
                int p = max_element(d.begin(), d.end()) - d.begin();
                dijkstra2 = Dijkstra(g, p);

                e = dijkstra2.distanceList();
            }

            long long get(){
                return *max_element(e.begin(), e.end());
            }

            vector<int> path(){
                return dijkstra2.getPath(max_element(e.begin(), e.end()) - e.begin());
            }

        private:
            vector<ll> e;
            Dijkstra dijkstra2;
        };
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<pair<int, ll>>> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; ll c; cin >> a >> b >> c;
        // a--, b--;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    shiroha::tree::WeightedDiameter wdiam(g);
    cout << wdiam.get() << " ";
    auto path = wdiam.path();
    cout << path.size() << endl;
    for(int v : path) cout << v << " ";
    cout << endl;
}