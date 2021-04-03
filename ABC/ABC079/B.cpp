#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<long long> age(3, 0); int n; cin >> n;
  if(n == 1){cout << 1 << endl; return 0;}
  age[1] = 2; age[2] = 1;
  for(int i = 2; i <= n; i++){
    age[0] = age[1]; age[1] = age[2];
    age[2] = age[0] + age[1];
  }
  cout << age[2] << endl;
}