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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
    // 入力を受け取る
    int n; cin >> n;
    int q; cin >> q;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    // 二部グラフとして彩色する
    queue<int> qu;
    qu.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    vector<int> depth(n, INT_MAX);
    depth[0] = 0;

    while(!qu.empty()){
        int seeing = qu.front();
        qu.pop();

        for(int next : graph[seeing]){
            if(visited[next]) continue;
            qu.push(next);
            depth[next] = (depth[seeing] + 1) % 2;
            visited[next] = true;
        }
    }

    // クエリを処理する
    query(q){
        int c, d; cin >> c >> d;
        int res = (depth[c - 1] + depth[d - 1]) % 2;
        if(res){
            cout << "Road" << endl;
        }else{
            cout << "Town" << endl;
        }
    }
}
