#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t; cin >> n >> t;
  vector<int> ts(n);
  for(int i = 0; i < n; i++){
    cin >> ts[i];
  }
  
  int lt = 0, nt = 0, ln = 0, ans = 0;
  while(true){
    if(ts[ln] == nt){
      lt = t; ln++;
    }
    if(lt > 0){
      ans++; lt--;
    }
    if(lt == 0 && ln >= n){
      break;
    }
    nt++;
  }
  cout << ans << endl;
}