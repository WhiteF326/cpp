#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  vector<int> n(10);
  for(int i = 0; i < 4; i++){
    int s; cin >> s; n[s]++;
  }
  if(n[1] == 1 && n[9] == 1 && n[7] == 1 && n[4] == 1) cout << "YES";
  else cout << "NO";
  cout << endl;
}