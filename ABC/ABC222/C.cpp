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
  vector<string> hands(n * 2);
  aryin(hands, n * 2);

  vector<pair<int, int>> u(n * 2);
  for(int i = 0; i < n * 2; i++) u[i].second = i;

  for(int i = 0; i < m; i++){
    sort(all(u), [&](pair<int, int> a, pair<int, int> b){
      if(a.first == b.first){
        return a.second < b.second;
      }else{
        return a.first > b.first;
      }
    });
    for(int j = 0; j < n; j++){
      int l = u[j * 2].second;
      int r = u[j * 2 + 1].second;

      char lh = hands[l][i];
      char rh = hands[r][i];

      if(lh == rh) continue;
      if(lh == 'G'){
        if(rh == 'C') u[j * 2].first++;
        else u[j * 2 + 1].first++;
      }else if(lh == 'C'){
        if(rh == 'P') u[j * 2].first++;
        else u[j * 2 + 1].first++;
      }else{
        if(rh == 'G') u[j * 2].first++;
        else u[j * 2 + 1].first++;
      }
    }
  }

  sort(all(u), [&](pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
      return a.second < b.second;
    }else{
      return a.first > b.first;
    }
  });
  for(int i = 0; i < 2 * n; i++){
    cout << u[i].second + 1 << endl;
  }
}