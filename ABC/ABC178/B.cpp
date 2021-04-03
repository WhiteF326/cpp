#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n;
  int tmp = 0;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    if(a == b){tmp++;}else{tmp = 0;}
    if(tmp == 3){cout << "Yes" << endl; return 0;}
  }
  cout << "No" << endl;
}