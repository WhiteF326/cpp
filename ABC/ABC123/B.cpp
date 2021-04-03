#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> t(5); int ms = 10;
  for(int i = 0; i < 5; i++){
    cin >> t[i];
    if(t[i] % 10 != 0){ms = min(ms, t[i] % 10);}
  }
  int ans = 0, dflg = 0;
  for(int i = 0; i < 5; i++){
    if(dflg == 0 && t[i] % 10 == ms){ans += t[i]; dflg = t[i];}
    else{ans += ((int)ceil(t[i] / 10.0)) * 10;}
  }
  cout << ans << endl;
}