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


struct msetsgt {
  vector<multiset<int, greater<int>>> v;
  vector<int> res;
  int n, m;

  msetsgt(int size){
    int b = ceil(log2(size));
    n = pow(2, b);
    v.resize(n);
    m = n * 2 - 1;
    res.resize(m);
    fill(all(res), INT_MAX);
  }

  // 追加更新
  void append(int p, int val){
    v[p].insert(val);
    int np = p + n - 1;
    res[np] = *(v[p].begin());
    while(np > 0){
      np = (np - 1) / 2;
      res[np] = min(res[np * 2 + 1], res[np * 2 + 2]);
    }
  }
  // 削除更新
  bool remove(int p, int val){
    auto itr = v[p].find(val);
    if(itr != v[p].end()){
      v[p].erase(itr);
      int np = p + n - 1;
      res[np] = v[p].size() == 0 ? INT_MAX : *(v[p].begin());
      while(np > 0){
        np = (np - 1) / 2;
        res[np] = min(res[np * 2 + 1], res[np * 2 + 2]);
      }
      return true;
    }else{
      return false;
    }
  }

  // 全取得
  int fullprod(){
    return res[0];
  }

  auto getl(){
    return v;
  }
};

int main(){
  int n, q; cin >> n >> q;
  
  msetsgt s(200000);
  vector<pair<int, int>> cur(n);
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    s.append(b - 1, a);
    cur[i] = mp(a, b - 1);
  }
  query(q){
    int c, d; cin >> c >> d;
    s.remove(cur[c - 1].second, cur[c - 1].first);
    s.append(d - 1, cur[c - 1].first);
    cur[c - 1].second = d - 1;
    cout << s.fullprod() << endl;
  }

  // auto l = s.getl();
  // for(auto ll : l){
  //   if(!ll.size()) continue;
  //   for(auto v : ll) cout << v << " ";
  //   cout << endl;
  // }
}