#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define ll long long
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