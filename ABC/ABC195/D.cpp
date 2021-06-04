#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

bool res(pair<int, int> a, pair<int, int> b){
  return a.second > b.second;
}

int main(){
  int n, m, q; cin >> n >> m >> q;
  vector<pair<int, int>> items(n, pair<int, int>());
  for(int i = 0; i < n; i++){
    int w, v; cin >> w >> v;
    items[i] = mp(w, v);
  }
  sort(items.begin(), items.end(), res);
  vector<int> box(m);
  for(int i = 0; i < m; i++) cin >> box[i];
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    l--;
    vector<int> tbox(box);
    tbox.erase(tbox.begin() + l, tbox.begin() + r);
    sort(tbox.begin(), tbox.end());
    vector<int> anslist(tbox.size(), 0);
    for(int j = 0; j < n; j++){
      for(int k = 0; k < tbox.size(); k++){
        if(tbox[k] >= items[j].first && anslist[k] == 0){
          anslist[k] = items[j].second;
          break;
        }
      }
    }
    cout << accumulate(anslist.begin(), anslist.end(), 0) << endl;
  }
}