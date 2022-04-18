#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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


class topologicalSort{
public:
    topologicalSort(const vector<vector<int>>& g) : n(int(g.size())){
        lst = vector<int>(n);

        vector<int> inc(n, 0);
        for(int i = 0; i < n; i++){
            for(int v : g[i]){
                inc[v]++;
            }
        }

        // sorting
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!inc[i]) q.push(i);
        }

        int ptr = 0;
        while(!q.empty()){
            int d = q.front();
            q.pop();

            lst[ptr] = d;
            ptr++;
            for(int v : g[d]){
                inc[v]--;
                if(!inc[v]){
                    q.push(v);
                }
            }
        }

        if(ptr == n){
            succeed = true;
        }else{
            succeed = false;
        }
    }

    bool isDAG(){
        return succeed;
    }

    vector<int>& get(){
        return lst;
    }

private:
    int n;
    vector<int> lst;
    bool succeed;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    query(m){
        int x, y; cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    auto tps = topologicalSort(g);
    assert(tps.isDAG());

    auto ls = tps.get();

    vector<int> dp(n, 0);

    for(int i = 0; i < n; i++){
        for(int v : g[ls[i]]){
            chmax(dp[v], dp[ls[i]] + 1);
        }
    }

    cout << *max_element(all(dp)) << endl;
}
