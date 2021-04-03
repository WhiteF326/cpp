#include <bits/stdc++.h>
using namespace std;

int main(){
  long a, b; cin >> a >> b;
  string ans;
  if(a > 0 && b > 0){ans = "Positive";}
  else if(a == 0 || b == 0){ans = "Zero";}
  else if((a > 0 && b < 0) || (a < 0 && b > 0)){ans = "Zero";}
  else if((a - b) % 2){ans = "Positive";}else{ans = "Negative";}
  cout << ans << endl;
}