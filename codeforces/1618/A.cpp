#include <bits/stdc++.h>
using namespace std;

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
  int t; cin >> t;
  query(t){
    int a, b, c, d, e, f, g; cin >> a >> b >> c >> d >> e >> f >> g;
    vector<int> bls = {a, b, c, d, e, f, g};
    vector<int> crs = {g - a, g - b, g - c, g - d, g - e, g - f};
    bool end = false;
    for(int i = 0; i < 4; i++){
      for(int j = i + 1; j < 5; j++){
        for(int k = i + 2; k < 6; k++){
          vector<int> c = {crs[i], crs[j], crs[k]};
          vector<int> cb = {c[0], c[1], c[2], c[0] + c[1], c[1] + c[2], c[0] + c[2], c[0] + c[1] + c[2]};
          sort(all(cb));
          bool ans = true;
          for(int v = 0; v < 7; v++){
            if(bls[v] != cb[v]) ans = false;
          }
          if(ans){
            cout << c[0] << " " << c[1] << " " << c[2] << endl;
            end = true;
            break;
          }
        }
        if(end) break;
      }
      if(end) break;
    }
  }
}