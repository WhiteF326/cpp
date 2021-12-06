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
  int n; cin >> n;
  vector<vector<int>> v(n, vector<int>(5));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 5; j++) cin >> v[i][j];
  }

  int l = 0, r = 1000000001;

  while(abs(l - r) > 1){
    int c = l + (r - l) / 2;
    vector<int> st(32, 0);
    for(auto w : v){
      int res  = 0;
      for(int j = 0; j < 5; j++){
        if(w[j] >= c) res += (1 << j);
      }
      st[res] = 1;
    }

    bool found = false;

    for(int a = 0; a < 32; a++){
      for(int b = 0; b < 32; b++){
        for(int c = 0; c < 32; c++){
          if(st[a] && st[b] && st[c] && (a | b | c) == 31){
            // found
            found = true;
            break;
          }
        }
        if(found) break;
      }
      if(found) break;
    }

    if(found){
      l = c;
    }else{
      r = c;
    }
  }

  cout << l << endl;
}