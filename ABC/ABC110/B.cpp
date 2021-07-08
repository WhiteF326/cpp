#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, m; cin >> n >> m;
  int x, y; cin >> x >> y;
  vector<int> xr(n), yr(m);

  for(int i = 0; i < n; i++) cin >> xr[i];
  for(int i = 0; i < m; i++) cin >> yr[i];

  int mxr = *max_element(xr.begin(), xr.end());
  int myr = *min_element(yr.begin(), yr.end());

  for(int i = x + 1; i <= y; i++){
    if(mxr < i && i <= myr){
      cout << "No War" << endl;
      return 0;
    }
  }
  cout << "War" << endl;
}