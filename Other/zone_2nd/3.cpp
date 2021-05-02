#include <bits/stdc++.h>
using namespace std;

int main(){
  //
  int ti = clock();
  int n, m; cin >> n >> m;
  vector<vector<int>> p(n, vector<int>(0));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  int mx = 0;
  vector<vector<int>> anslist(n * n * n, vector<int>(4));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        if(i == j || j == k || i == k) continue;
        set<int> ans;
        ans.insert(i);
        ans.insert(j);
        ans.insert(k);
        for(int a = 0; a < p[i].size(); a++) ans.insert(p[i][a]);
        for(int a = 0; a < p[j].size(); a++) ans.insert(p[j][a]);
        for(int a = 0; a < p[k].size(); a++) ans.insert(p[k][a]);
        vector<int> px = {i, j, k};
        anslist[i * n * n + j * n + k][0] = ans.size();
        mx = max(mx, (int)ans.size());
        for(int a = 0; a < 3; a++) anslist[i * n * n + j * n + k][a + 1] = px[a];
      }
    }
  }
  for(int i = 0; i < anslist.size(); i++){
    if(anslist[i][0] == mx){
      cout << anslist[i][1] << " " << anslist[i][2] << " " << anslist[i][3] << endl;
    }
  }
  int ti2 = clock();
  cout << ti2 - ti << endl;
}