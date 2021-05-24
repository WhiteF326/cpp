#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int op(int a, int b){
  return a ^ b;
}

int e(){
  return (2 << 30) + 1;
}

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  segtree<int, op, e> seg(a);

  for(int i = 0; i < q; i++){
    int t, x, y; cin >> t >> x >> y;
    x--;
    if(t == 1){
      seg.set(x, y);
    }else{
      cout << seg.prod(x, y);
    }
  }
}