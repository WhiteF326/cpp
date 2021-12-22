#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define all(a) a.begin(), a.end()

// persistent Union-Find, knowledges from https://camypaper.bitbucket.io/2016/12/18/adc2016/
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
    while(q){
        q--;
        int x, y, z; cin >> x >> y >> z;
        int l = 0, r = m;
        int mid = 0;
        while(r - l > 1){
            mid = (l + r) / 2;
            // check
            int size = 0;
            if(d.same(mid, x - 1, y - 1)){
                size = d.size(mid, x - 1);
            }else{
                size = d.size(mid, x - 1) + d.size(mid, y - 1);
            }
            if(size >= z){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << l + 1 << endl;
    }
}