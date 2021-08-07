#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  map<int, int> c;
  for(int v : a){
    c[v]++;
  }

  sort(a.begin(), a.end());
  
  map<int, bool> app;
  int ans = 0;
  for(auto x : c){
    if(x.second > 1){
      app[x.first] = true;
      continue;
    }
    bool flg = true;
    for(int i = 1; i <= sqrt(x.first); i++){
      if(x.first % i) continue;
      if(app[x.first / i] || app[i]){
        flg = false;
        break;
      }
    }
    ans += flg;
    app[x.first] = true;
  }
  cout << ans << endl;
}
