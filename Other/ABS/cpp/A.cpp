#include<bits/stdc++.h>
using namespace std;

int main(){
  int r = 0;
  for(int i = 0; i < 3; i++){
    int t; cin >> t; r += t;
  }
  string t;
  cin >> t;
  cout << r << " " + t << endl;
}