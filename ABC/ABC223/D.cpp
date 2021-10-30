#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> res(n);
  vector<int> inc(n, 0);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    res[a - 1].push_back(b - 1);
    inc[b - 1]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 0; i < n; i++) if(!inc[i]) q.push(i);

  vector<int> tps;

  while(!q.empty()){
    int dest = q.top();
    q.pop();

    tps.push_back(dest);
    for(auto v : res[dest]){
      inc[v]--;
      if(!inc[v]){
        q.push(v);
      }
    }
  }

  if(tps.size() == n){
    // dag である
    for(auto v : tps) cout << v + 1 << " ";
    cout << endl;
  }else{
    cout << -1 << endl;
  }
}