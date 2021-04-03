#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  long long ans = 0, res = s.length() - 1;
  for(int i = s.length() - 1; i >= 0; i--){
    if(s.substr(i, 1) == "B"){
      ans += res - i; res--;
    }
  }
  cout << ans << endl;
}