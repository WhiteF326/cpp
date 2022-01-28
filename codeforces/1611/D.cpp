#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<vector<int>> g(n);
    int root = 0;
    for(int i = 0; i < n; i++){
      int a; cin >> a;
      a--;
      if(a == i){
        root = i;
      }else{
        g[a].push_back(i);
      }
    }

    vector<int> p(n);
    for(int i = 0; i < n; i++){
      int a; cin >> a;
      p[a - 1] = i;
    }

    queue<int> q;
    q.push(root);
    vector<int> len(n, 0);

    bool flg = true;
    while(!q.empty()){
      int dest = q.front();
      q.pop();

      for(int v : g[dest]){
        if(p[v] < p[dest]){
          flg = false;
          break;
        }else{
          q.push(v);
          len[v] = p[v] - p[dest];
        }
      }

      if(!flg){
        break;
      }
    }

    if(flg){
      for(int v : len) cout << v << " ";
      cout << endl;
    }else{
      cout << -1 << endl;
    }
  }
}