#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  unordered_map<int, int> vo, ve;
  for(int i = 0; i < n; i++){
    int v; cin >> v;
    if(i % 2) vo[v]++;
    else ve[v]++;
  }
  vector<int> dls_o, dls_e;
  for(auto i : vo){
    dls_o.emplace_back(n / 2 - i.second);
  }
  dls_o.emplace_back(n / 2);
  for(auto i : ve){
    dls_e.emplace_back(n / 2 - i.second);
  }
  dls_e.emplace_back(n / 2);
  sort(dls_o.begin(), dls_o.end());
  sort(dls_e.begin(), dls_e.end());

  auto mdo = min_element(vo.begin(), vo.end(), [](const auto &a, const auto &b) -> bool{
    return(a.second > b.second);
  });
  auto mde = min_element(ve.begin(), ve.end(), [](const auto &a, const auto &b) -> bool{
    return(a.second > b.second);
  });
  if(mdo->first == mde->first){
    cout << dls_o[1] + dls_e[0] << " " << dls_o[0] + dls_e[1] << endl;
    cout << min(dls_o[1] + dls_e[0], dls_o[0] + dls_e[1]) << endl;
  }else{
    cout << dls_o[0] + dls_e[0] << endl;
  }
}