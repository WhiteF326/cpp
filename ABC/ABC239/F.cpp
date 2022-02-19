#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> d(n);
  aryin(d, n);

  if(2 * n - 2 != accumulate(all(d), 0)){
    cout << -1 << endl;
    return 0;
  }

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    d[a - 1]--;
    d[b - 1]--;
  }

  queue<pair<int, int>> ls, lv, ans;
  for(int i = 0; i < n; i++){
    if(d[i] == 1){
      ls.push({i, 1});
    }else if(d[i]){
      lv.push({i, d[i]});
    }
  }

  while(!ls.empty() && !lv.empty()){
    auto p = ls.front();
    auto q = lv.front();
    ls.pop();
    lv.pop();

    ans.push({p.first, q.first});

    q.second--;
    if(q.second == 1){
      ls.push(q);
    }else{
      lv.push(q);
    }
  }

  if(ls.size() != 2){
    cout << -1 << endl;
  }else{
    auto p = ls.front();
    ls.pop();
    auto q = ls.front();
    ls.pop();

    if(p.second == 1 && q.second == 1){
      while(!ans.empty()){
        cout << ans.front().first + 1 << " " << ans.front().second + 1 << endl;
        ans.pop();
      }
      cout << p.first + 1 << " " << q.first + 1 << endl;
    }else{
      cout << -1 << endl;
    }
  }
}
