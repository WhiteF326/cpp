#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k, m; cin >> n >> k >> m;
  int a = 0;
  for(int i = 0; i < n - 1; i++){
    int x; cin >> x;
    a += x;
  }
  if(m * n - a <= k){
    cout << max(0, m * n - a) << endl;
  }else cout << -1 << endl;
}