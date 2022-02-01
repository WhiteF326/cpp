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
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m, q; cin >> n >> m >> q;
  vector<pair<int, int>> items(n);
  for(int i = 0; i < n; i++){
    cin >> items[i].first >> items[i].second;
  }

  sort(all(items), [](const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second;
  });
  vector<int> box(m);
  for(int i = 0; i < m; i++) cin >> box[i];

  query(q){
    int l, r; cin >> l >> r;
    l--;

    vector<int> tbox(box);
    tbox.erase(tbox.begin() + l, tbox.begin() + r);
    sort(all(tbox));

    vector<int> anslist(tbox.size(), 0);

    for(int j = 0; j < n; j++){
      for(int k = 0; k < tbox.size(); k++){
        if(tbox[k] >= items[j].first && anslist[k] == 0){
          anslist[k] = items[j].second;
          break;
        }
      }
    }

    cout << accumulate(all(anslist), 0) << endl;
  }
}