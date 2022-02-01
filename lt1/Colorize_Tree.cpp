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
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    // 頂点 1 を黒色とし、BFS で頂点 1 から各頂点への距離を求める
    queue<int> q;
    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    vector<int> depth(n, INT_MAX);
    depth[0] = 0;

    while(!q.empty()){
        int seeing = q.front();
        q.pop();

        for(int next : graph[seeing]){
            if(visited[next]) continue;
            q.push(next);
            depth[next] = depth[seeing] + 1;
            visited[next] = true;
        }
    }

    // 出力
    for(int i = 0; i < n; i++){
        if(depth[i] % 2 == 0){
            cout << "Black" << endl;
        }else{
            cout << "White" << endl;
        }
    }
}
