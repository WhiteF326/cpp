#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
  vector<int> c(3); for(int i = 0; i < 3; i++) cin >> c[i];
  sort(c.begin(), c.end());
  if(c[0] == c[1] + c[2] || c[0] + c[1] == c[2]){
    cout << "Yes";
  }else cout << "No";
  cout << endl;
}