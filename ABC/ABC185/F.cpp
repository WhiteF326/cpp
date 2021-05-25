#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;

int op(int a, int b){
  return a ^ b;
}

int e(){
  return 0;
}

int main(){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  segtree<int, op, e> seg(a);

  queue<int> anslist;

  for(int i = 0; i < q; i++){
    int t, x, y; cin >> t >> x >> y;
    x--;
    if(t == 1){
      seg.set(x, seg.get(x) ^ y);
    }else{
      anslist.push(seg.prod(x, y));
    }
  }

  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}