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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


#define mint modint1000000007
#define mtrx vector<vector<mint>>

mtrx mtrxMul(mtrx &a, mtrx &b) {
  mtrx res(a.size(), vector<mint>(b[0].size()));
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < b[0].size(); j++){
      for(int k = 0; k < b.size(); k++){
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}
mtrx mtrxPow(mtrx a, ll n){
  mtrx res(a.size(), vector<mint>(a.size()));
  for(int i = 0; i < a.size(); i++){
    res[i][i] = 1;
  }
  while(n > 0){
    if(n & 1) res = mtrxMul(a, res);
    a = mtrxMul(a, a);
    n >>= 1;
  }
  return res;
}
int main(){
  int s; cin >> s;
  if(s <= 3){
    if(s == 3){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
    return 0;
  }

  mtrx act(3, vector<mint>(3, 0));
  act[0][0] = 1, act[0][1] = 0, act[0][2] = 1;
  act[1][0] = 1, act[1][1] = 0, act[1][2] = 0;
  act[2][0] = 0, act[2][1] = 1, act[2][2] = 0;

  mtrx res = mtrxPow(act, s - 3);
  cout << res[0][0].val() << " ";
}