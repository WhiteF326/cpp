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
  set<int, greater<int>> trg;
  for(int i = 0; i < n; i++) trg.insert(i);
  if(n % 2 == 0) trg.erase(n / 2);

  vector<bool> used(n + 1, false);
  int solved = 0;
  for(int i = 1; i <= n; i++){
    auto v = trg.begin();
    if(i + *v > n){
      trg.erase(v);
      i--;
      continue;
    }
    if(!used[i] && !used[i + *v]){
      used[i] = 1;
      used[i + *v] = 1;
      cout << i << " " << i + *v << endl;
      
      vector<int> rem{*v, n - *v};
      for(int l : rem) trg.erase(l);

      solved++;
      if(solved == m) return 0;
    }
  }
}