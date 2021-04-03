#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; bool ans = true;
  string w; cin >> w;
  vector<string> wst(n, "");
  wst[0] = w;
  string llet = w.substr(w.length() - 1);
  for(int i = 1; i < n; i++){
    cin >> w;
    if(llet != w.substr(0, 1)){
      ans = false; break;
    }else{
      for(int j = 0; j < i; j++){
        if(wst[j] == w){ans = false; break;}
      }
      if(!ans){break;}
      wst[i] = w; llet = w.substr(w.length() - 1);
    }
  }
  if(ans){cout << "Yes" << endl;}
  else{cout << "No" << endl;}
}