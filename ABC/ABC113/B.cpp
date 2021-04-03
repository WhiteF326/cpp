#include <bits/stdc++.h>
using namespace std;

int main(){
  double n, t, a; cin >> n >> t >> a; vector<double> h(n);
  vector<double> dif(n); double mindif = DBL_MAX;
  for(int i = 0; i < n; i++){
    cin >> h[i];
    dif[i] = abs(a - (t - h[i] * 0.006));
    mindif = min(mindif, dif[i]);
  }
  for(int i = 0; i < n; i++){
    if(dif[i] == mindif){cout << i + 1 << endl; return 0;}
  }
}