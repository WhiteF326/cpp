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
            BFS(vector<vector<int>>& g, int start = 0){
                queue<int> q;
                q.push(start);

                visited.assign(g.size(), 0);
                visited[start] = 1;
                depth.assign(g.size(), 0);

                while(!q.empty()){
                    int dest = q.front();
                    q.pop();

                    for(const int& v : g[dest]){
                        if(visited[v]) continue;
                        visited[v] = true;
                        depth[v] = depth[dest] + 1;
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
        };
        class Diameter {
        public:
            Diameter(vector<vector<int>>& g){
                BFS bfs1(g, 0);
                vector<int> d = bfs1.distanceList();
                int p = max_element(d.begin(), d.end()) - d.begin();
                BFS bfs2(g, p);

                e = bfs2.distanceList();
            }

            int get(){
                return *max_element(e.begin(), e.end());
            }

        private:
            vector<int> e;
        };
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    shiroha::tree::Diameter diam(g);
    cout << diam.get() + 1 << endl;
}