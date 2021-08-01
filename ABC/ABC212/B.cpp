#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  string s; cin >> s;
  for(int i = 0; i < 2; i++){
    bool t = false;
    for(int j = 0; j < 3; j++){
      if((s[j + 1] - s[j] + 10) % 10 != i) t = true;
    }
    if(!t){
      cout << "Weak" << endl;
      return 0;
    }
  }
  cout << "Strong" << endl;
}