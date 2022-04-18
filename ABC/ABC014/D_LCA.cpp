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


// dependency
namespace shiroha {
    namespace datastructure {
        template<typename T>
        class SparseTable {
        public:
            SparseTable() {}
            SparseTable(const vector< T > &v) {
                int b = 0;
                while((1 << b) <= v.size()) ++b;
                st.assign(b, vector< T >(1 << b));
                for(int i = 0; i < v.size(); i++) {
                    st[0][i] = v[i];
                }
                for(int i = 1; i < b; i++) {
                    for(int j = 0; j + (1 << i) <= (1 << b); j++) {
                        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                    }
                }
                lookup.resize(v.size() + 1);
                for(int i = 2; i < lookup.size(); i++) {
                    lookup[i] = lookup[i >> 1] + 1;
                }
            }

            inline T prod(int l, int r) {
                int b = lookup[r - l];
                return min(st[b][l], st[b][r - (1 << b)]);
            }
        private:
            vector<vector<T>> st;
            vector<int> lookup;
        };

        template<class T, T (*op)(T, T)>
        class AnySparseTable {
        public:
            AnySparseTable() {}
            AnySparseTable(const vector< T > &v) {
                int b = 0;
                while((1 << b) <= v.size()) ++b;
                st.assign(b, vector< T >(1 << b));
                for(int i = 0; i < v.size(); i++) {
                    st[0][i] = v[i];
                }
                for(int i = 1; i < b; i++) {
                    for(int j = 0; j + (1 << i) <= (1 << b); j++) {
                        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
                    }
                }
                lookup.resize(v.size() + 1);
                for(int i = 2; i < lookup.size(); i++) {
                    lookup[i] = lookup[i >> 1] + 1;
                }
            }

            inline T prod(int l, int r) {
                int b = lookup[r - l];
                return op(st[b][l], st[b][r - (1 << b)]);
            }
        private:
            vector<vector<T>> st;
            vector<int> lookup;
        };
    }
}
// dependency end

namespace shiroha {
    namespace internal {
        struct Node{
            int value;
            int depth;
        };

        // 置き場所が悪い
        Node op(Node a, Node b){
            if(a.depth < b.depth){
                return a;
            }else{
                return b;
            }
        }
    }

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

        struct DFS {
            vector<bool> visited;
            vector<int> depth;
            vector<int> from;

            vector<int> euler;
            vector<int> in, out;
            int cnt = 0;
            DFS() {}
            DFS(vector<vector<int>>& g, int start = 0){
                visited.assign(g.size(), 0);
                visited[start] = 1;
                depth.assign(g.size(), 0);
                from.assign(g.size(), -1);

                euler.assign(g.size() * 2 - 1, -1);
                euler[0] = start;
                in.assign(g.size(), -1);
                in[start] = 0;
                out.assign(g.size(), -1);

                recursive(g, start);
            }

            void recursive(vector<vector<int>>& g, int p){
                in[p] = cnt;
                euler[cnt] = p;
                cnt++;
                for(int v : g[p]){
                    if(visited[v]) continue;
                    visited[v] = true;

                    from[v] = p;
                    depth[v] = depth[p] + 1;

                    recursive(g, v);
                    euler[cnt] = p;
                    cnt++;
                }
                out[p] = cnt;
            }

            vector<int> eulerTour(){
                return euler;
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

        class LCA {
        public:
            LCA(vector<vector<int>>& g, int root = 0){
                dfs = DFS(g, 0);
                vector<internal::Node> v(g.size() * 2 - 1);
                for(int i = 0; i < g.size() * 2 - 1; i++){
                    v[i].value = dfs.euler[i];
                    v[i].depth = dfs.depth[v[i].value];
                }
                st = shiroha::datastructure::AnySparseTable<internal::Node, internal::op>(v);
            }

            int get(int u, int v){
                if(dfs.in[u] > dfs.out[v]) swap(u, v);
                return st.prod(dfs.in[u], dfs.out[v]).value;
            }

            int dist(int u, int v){
                return dfs.depth[u] + dfs.depth[v] - dfs.depth[get(u, v)] * 2;
            }

        private:
            DFS dfs;
            shiroha::datastructure::AnySparseTable<internal::Node, internal::op> st;
        };
        
        /**
         * ワーシャルフロイド法によって、全長点組間の距離を求める。
         * Complexity : Ο(N^3)
         * 
         * 直接辺で結ばれた頂点 a -> b について、その辺の重みを d[a][b] に格納し、
         * 直接結ばれてはいない頂点組には全て inf を格納した配列を渡す。
        */
        template<typename T>
        void warshallFloyd(vector<vector<T>> &d){
            int n = d.size();
            for (int k = 0; k < n; k++){
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    shiroha::tree::LCA lca(g);

    int q; cin >> q;
    query(q){
        int a, b; cin >> a >> b;
        cout << lca.dist(a - 1, b - 1) + 1 << "\n";
    }
    fflush(stdout);
}