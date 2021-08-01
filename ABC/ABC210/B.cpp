#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int n; cin >> n;
  string x; cin >> x;
  for(int i = 0; i < n; i++){
    if(x[i] == '1'){
      cout << (i % 2 ? "Aoki" : "Takahashi") << endl;
      break;
    }
  }
}