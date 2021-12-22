#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  int m; cin >> m;

  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }

  vector<vector<bool>> h(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    h[a - 1][b - 1] = true;
    h[b - 1][a - 1] = true;
  }

  vector<int> perm(n);
  for(int i = 0; i < n; i++) perm[i] = i;

  do{
    bool flg = true;
    for(int i = 0; i < n; i++){
      for(int v : g[i]){
        if(!h[perm[i]][perm[v]]){
          flg = false;
        }
      }
    }

    if(flg){
      cout << "Yes" << endl;
      return 0;
    }
  }while(next_permutation(all(perm)));

  cout << "No" << endl;
}