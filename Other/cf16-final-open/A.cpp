#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      string s; cin >> s;
      if(s == "snuke"){
        cout << (char)('A' + j) + to_string(i + 1) << endl;
      }
    }
  }
  return 0;
}