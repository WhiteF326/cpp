#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  ll a, b, c, d; cin >> a >> b >> c >> d;
  if(b >= c * d) cout << "-1" << endl;
  else{
    // once c - b
    ll w = a, r = 0;
    int x = 0;
    while(true){
      if(r * d >= w){
        cout << x << endl;
        return 0;
      }
      w += b, r += c, x++;
    }
  }
}