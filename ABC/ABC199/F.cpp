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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


const ll modv = 1000000007;
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
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m, k; cin >> n >> m >> k;
  vector<vector<mint>> al(n, vector<mint>(1));
  for(int i = 0; i < n; i++){
    int d; cin >> d;
    al[i][0] = d;
  }

  mtrx x(n, vector<mint>(n, 0));
  for(int i = 0; i < n; i++){
    x[i][i] = m * 2;
  }
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    x[a][b]++;
    x[b][a]++;
    x[a][a]--;
    x[b][b]--;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      x[i][j] /= (m * 2);
    }
  }

  mtrx xp = mtrxPow(x, k);
  mtrx anslist = mtrxMul(xp, al);

  for(int i = 0; i < n; i++){
    cout << anslist[i][0].val() << endl;
  }
}