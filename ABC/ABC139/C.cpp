#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  // 単調減少である最大の部分列の長さ-1
  int ans = 0;
  int res = 0;
  for(int i = 1; i < n; i++){
    if(h[i] <= h[i - 1]){
      res++;
    }else{
      ans = max(ans, res);
      res = 0;
    }
  }
  ans = max(ans, res);
  cout << ans << endl;
}