#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n, q; cin >> n >> q;
  vector<vector<int>> gr(n, vector<int>(0));
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  vector<int> anslist(n, 0);
  for(int i = 0; i < q; i++){
    int p, x; cin >> p >> x;
    anslist[p - 1] += x;
  }

  // bfs
  vector<bool> visited(n, false);
  visited[0] = true;
  queue<int> qu;
  qu.push(0);
  while(!qu.empty()){
    int dest = qu.front();
    qu.pop();
    for(int i = 0; i < gr[dest].size(); i++){
      if(visited[gr[dest][i]] == false){
        visited[gr[dest][i]] = true;
        anslist[gr[dest][i]] += anslist[dest];
        qu.push(gr[dest][i]);
      }
    }
  }

  for(int i = 0; i < n - 1; i++){
    cout << anslist[i] << " ";
  }cout << anslist.back() << endl;
  
}