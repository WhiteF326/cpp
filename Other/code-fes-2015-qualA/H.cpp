#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

class pdsu{
    public:
        const int inf = 1000000000;
        int now = 0;
        vector<int> parent;
        vector<int> time;
        vector<vector<pair<int, int>>> num;

        pdsu(int n){
            parent.resize(n);
            fill(all(parent), -1);
            time.resize(n);
            fill(all(time), inf);
            num.resize(n);
            for(int i = 0; i < n; i++){
                num[i].push_back({0, 1});
            }
        }

        int find(int t, int x){
            while(time[x] <= t){
                x = parent[x];
            }
            return x;
        }

        void merge(int x, int y){
            now++;
            x = find(now, x);
            y = find(now, y);

            if(x == y) return;

            if(parent[x] > parent[y]){
                swap(x, y);
            }

            parent[x] += parent[y];
            parent[y] = x;
            time[y] = now;
            num[x].push_back({now, -parent[x]});
        }

        bool same(int t, int x, int y){
            return find(t, x) == find(t, y);
        }

        int size(int t, int x){
            x = find(t, x);

            int ok = 0, ng = num[x].size();
            while(ng - ok > 1){
                int mid = (ok + ng) / 2;
                if(num[x][mid].first <= t){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            return num[x][ok].second;
        }
};


int main(){
    int n, m; cin >> n >> m;

    pdsu d(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        d.merge(a - 1, b - 1);
    }

    int q; cin >> q;
    query(q){
        int x, y; cin >> x >> y;
        x--, y--;
        if(d.same(m, x, y)){
            int ok = 0, ng = m;
            int mid = 0;
            while(ng - ok > 1){
                mid = (ok + ng) / 2;
                if(d.same(mid, x, y)){
                    ng = mid;
                }else{
                    ok = mid;
                }
            }
            cout << ok + 1 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}