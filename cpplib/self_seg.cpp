#include <bits/stdc++.h>
using namespace std;

#define ll long long


template <typename T>
struct SegTree{
  int h, s, el;

  vector<T> val;
  
  SegTree(const int& n){
    int nx = n;
    el = 1;
    h = 0;
    while(nx){
      nx >>= 1;
      h++;
      el <<= 1;
    }
    s = el << 1;
    val = vector<T>(s, e());
  }

  T get(const int& p){
    return val[p + el - 1];
  }
  void set(const int& p, const T& set){
    int xp = p + el - 1;
    val[xp] = set;
    while(xp > 0){
      xp = (xp - 1) / 2;
      val[xp] = merge(val[xp * 2 + 1], val[xp * 2 + 2]);
    }
  }

  T product(const int& l, const int& r){
    return product_sub(l, r, 0, s);
  }
  T product_sub(const int& l, const int& r, const int& a, const int& b){
    if(b <= l || r <= a){
      return e();
    }else if(l <= a && b <= r){
      // 区間幅から高さを取得
      int range = h - log2(b - a);
      int sl = (a / (b - a)) + (1 << range) - 1;
      return val[sl];
    }else{
      // 左半分
      T ql = product_sub(l, r, a, (a + b) / 2);
      T qr = product_sub(l, r, (a + b) / 2, b);
      return merge(ql, qr);
    }
  }

  // merge function
  T merge(const T& a, const T& b){
    return a ^ b;
  }

  // e function
  T e(){
    return 0;
  }
};

int main(){
  int n, q; cin >> n >> q;

  SegTree<ll> s(n);

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    s.set(i, a);
  }
  for(int i = 0; i < q; i++){
    int c; cin >> c;
    if(c == 1){
      // add
      int x, y; cin >> x >> y;
      s.set(x - 1, s.get(x - 1) ^ y);
    }else{
      // get
      int x, y; cin >> x >> y;
      cout << s.product(x - 1, y) << endl;
    }
  }
}