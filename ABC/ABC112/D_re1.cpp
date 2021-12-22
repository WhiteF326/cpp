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


int main(){
  int n, m; cin >> n >> m;
  
  set<int> md;
  for(int i = 1; i * i <= m; i++){
    if(m % i == 0){
      md.insert(i);
      md.insert(m / i);
    }
  }

  int ans = 1;
  for(int g : md){
    if(m / g >= n){
      ans = g;
    }
  }

  cout << ans << endl;
}