#include <bits/stdc++.h>
using namespace std;

int main(){
  string o, e; cin >> o >> e; string ans = "";
  for(int i = 0; i < (int)min(o.length(), e.length()); i++){
    ans += o.substr(i, 1) + e.substr(i, 1);
  }
  if(o.length() > e.length()){ans += o.substr(o.length() - 1, 1);}
  cout << ans << endl;
}