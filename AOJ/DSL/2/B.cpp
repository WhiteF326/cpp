#include <bits/stdc++.h>
using namespace std;

#define ll long long


struct seg{
  int h, s, el;

  vector<ll> val;
  
  seg(int n, ll v){
    h = ceil(log2(n));
    el = 1 << h;
    s = el << 1;
    val = vector<ll>(s, v);
  }

  ll get(int p){
    return val[p + el - 1];
  }
  void set(int p, ll set){
    p += el - 1;
    val[p] = set;
    while(p > 0){
      p = (p - 1) / 2;
      val[p] = merge(val[p * 2 + 1], val[p * 2 + 2]);
    }
  }

  ll product(int l, int r){
    return product_sub(l, r, 0, s);
  }
  ll product_sub(int l, int r, int a, int b){
    if(b <= l || r <= a){
      return e();
    }else if(l <= a && b <= r){
      // 区間幅から高さを取得
      int range = h - log2(b - a);
      int sl = (a / (b - a)) + (1 << range) - 1;
      return val[sl];
    }else{
      // 左半分
      ll ql = product_sub(l, r, a, (a + b) / 2);
      ll qr = product_sub(l, r, (a + b) / 2, b);
      return merge(ql, qr);
    }
  }

  // merge function
  ll merge(ll a, ll b){
    return a + b;
  }

  // e function
  ll e(){
    return 0;
  }
};

int main(){
  int n, q; cin >> n >> q;

  seg s(n, 0);
  for(int i = 0; i < q; i++){
    int c; cin >> c;
    if(c == 0){
      // add
      int x, y; cin >> x >> y;
      s.set(x - 1, s.get(x - 1) + y);
    }else{
      // get
      int x, y; cin >> x >> y;
      cout << s.product(x - 1, y) << endl;
    }
  }
}