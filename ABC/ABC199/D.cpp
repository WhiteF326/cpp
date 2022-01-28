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


struct Edge{
  int f, t, c;
  Edge(){
    this->f = 0;this->t = 0, this->c = 0;
  }
  Edge(int f, int t, int c){
    this->f = f, this->t = t, this->c = c;
  }
};
ostream& operator<< (ostream& os, const Edge& v){
  os << v.f << " " << v.t << " " << v.c;
  return os;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int l; cin >> l;

  vector<Edge> v;
  int n = 1;
  for(int i = 1; (1 << i) <= l; i++){
    v.push_back({i, i + 1, 0});
    v.push_back({i, i + 1, 1 << (i - 1)});
    n++;
  }

  int sink = n, f = n;
  n = 1 << (n - 1);
  int w = n;
  l -= n;

  while(l > 0){
    if(l >= n){
      v.push_back({f, sink, w});
      l -= n;
      w += n;
    }
    n >>= 1;
    f--;
  }

  cout << sink << " " << v.size() << endl;
  for(auto e : v){
    cout << e << endl;
  }
}