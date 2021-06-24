#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<pair<int, int>> st(n);
  for(int i = 0; i < n; i++){
    int c, p; cin >> c >> p;
    st[i] = mp(c, p);
  }
  vector<vector<int>> ac(2, vector<int>(n + 1, 0));
  for(int i = 0; i < n; i++){
    if(st[i].first == 1){
      ac[0][i + 1] = ac[0][i] + st[i].second;
      ac[1][i + 1] = ac[1][i];
    }else{
      ac[0][i + 1] = ac[0][i];
      ac[1][i + 1] = ac[1][i] + st[i].second;
    }
  }
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int l, r; cin >> l >> r;
    cout << ac[0][r] - ac[0][l - 1] << " " << ac[1][r] - ac[1][l - 1] << endl;
  }
}