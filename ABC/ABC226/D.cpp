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
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];

ll gcd(ll x, ll y){
  while(y > 0){
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main(){
  int n; cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

  set<pair<int, int>> s;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      int difx = x[i] - x[j];
      int dify = y[i] - y[j];
      int v = gcd(abs(difx), abs(dify));
      pair<int, int> p = {difx / v, dify / v};
      s.insert(p);
    }
  }

  cout << s.size() << endl;
}