#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

int main(){
  int l, q; cin >> l >> q;
  set<int> s;
  s.insert(0);
  s.insert(l);

  query(q){
    int c, x; cin >> c >> x;
    if(c == 1){
      s.insert(x);
    }else{
      auto itr = s.lower_bound(x);
      int h = *itr;
      itr--;
      int l = *itr;
      cout << h - l << endl;
    }
  }
}