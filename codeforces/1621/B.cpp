#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<int> l(n), r(n), c(n);
    int left = 1000000001, right = -1;
    int lc = INT_MAX, rc = INT_MAX;
    int lp = 0, rp = 0;
    for(int i = 0; i < n; i++){
      cin >> l[i] >> r[i] >> c[i];
    }
    for(int i = 0; i < n; i++){
      if(lp == rp){
        if(left > l[i] || (left == l[i] && c[i] + rc <= lc)){
          left = l[i];
          lp = i;
          lc = c[i];
        }
        if(right < r[i] || (right == r[i] && c[i] + lc <= rc)){
          right = r[i];
          rp = i;
          rc = c[i];
        }
      }else{
        if(left > l[i] || (left == l[i] && c[i] <= lc)){
          left = l[i];
          lp = i;
          lc = c[i];
          if(right == r[i]){
            rp = i;
            rc = c[i];
          }
        }
        if(right < r[i] || (right == r[i] && c[i] <= rc)){
          right = r[i];
          rp = i;
          rc = c[i];
          if(left == l[i]){
            lp = i;
            lc = c[i];
          }
        }
      }

      if(lp == rp){
        cout << lc << endl;
      }else{
        cout << lc + rc << endl;
      }
    }
  }
}