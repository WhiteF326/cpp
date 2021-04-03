#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; int tmp = 1, ans = 0;
  for(int i = 0; i < n; i++){
    int t; cin >> t;
    if(t != tmp){ans++;}else{tmp++;}
  }
  cout << (ans == n ? -1 : ans) << endl;
}