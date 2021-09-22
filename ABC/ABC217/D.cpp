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
  int l, q; cin >> l >> q;
  vector<pair<int, int>> queries(q);
  vector<int> cutted;
  map<int, pair<int, int>> searchs;
  for(int i = 0; i < q; i++){
    int c, x; cin >> c >> x;
    if(c == 1) cutted.push_back(x);
    else searchs[x] = mp(0, 0);
  }
  sort(all(cutted));
  sort(all(searchs));

  for(auto v : searchs){
    int val = v.first;
    searchs[v] = mp(
      cutted[lower_bound(all(cutted), x) - cutted.begin() - 1];
    )
  }
}