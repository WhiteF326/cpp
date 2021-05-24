#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int main(){
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  vector<ll> xoracc(n, 0);
  for(int i = 0; i < n; i++){
    ll d; cin >> d;
    a[i] = d;
  }
  xoracc[0] = a[0];
  for(int i = 1; i < n; i++){
    xoracc[i] = xoracc[i - 1] ^ a[i];
  }
  for(int i = 0; i < q; i++){
    int t, x, y; cin >> t >> x >> y;
    if(t == 1){
      x--;
      
      // 累積和を更新
    }else{
      x--, y--;
      cout << (xoracc[y] ^ xoracc[x - 1]) << endl;
    }
  }
}