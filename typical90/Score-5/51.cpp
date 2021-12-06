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


struct item{
  ll value;
  int size;
  
  item(ll value, int size){
    this->value = value;
    this->size = size;
  }

  item(ll value){
    this->value = value;
    size = 1;
  }

  item(){
    value = 0LL;
    size = 0;
  }

  bool operator< (const item& obj){
    return this->value < obj.value;
  }
  bool operator<= (const item& obj){
    return this->value <= obj.value;
  }

  item operator+ (const item& obj){
    return {this->value + obj.value, this->size + obj.size};
  }
};

ostream& operator<< (ostream& os, const item& it){
  os << "{" << it.value << ", " << it.size << "}";
  return os;
};
bool operator< (const ll& l, const item& r){
  return l < r.value;
}

int main(){
  int n, k; cin >> n >> k;
  ll p; cin >> p;
  vector<item> a(n);
  for(int i = 0; i < n; i++){
    ll x; cin >> x;
    a[i] = {x, 1};
  }

  int m = (n + (n % 2)) / 2;
  vector<vector<item>> ax(m + 1), bx(m + 1);
  for(int i = 0; i < (1 << m); i++){
    item ar;
    for(int j = 0; j < m; j++){
      if(i & (1 << j)){
        ar = ar + a[j];
      }
    }
    ax[ar.size].push_back(ar);
  }
  for(int i = 0; i < (1 << (m - (n % 2))); i++){
    item br;
    for(int j = 0; j < m; j++){
      if(i & (1 << j)){
        br = br + a[j + m];
      }
    }
    bx[br.size].push_back(br);
  }
  for(int i = 0; i <= m; i++){
    sort(all(ax[i]));
    sort(all(bx[i]));
  }

  ll ans = 0;
  for(int i = 0; i <= m; i++){
    int trg = k - i;
    if(trg < 0 || trg > m) continue;
    for(auto it : ax[i]){
      ans += (ll)(upper_bound(all(bx[trg]), p - it.value) - bx[trg].begin());
    }
  }

  cout << ans << endl;
}