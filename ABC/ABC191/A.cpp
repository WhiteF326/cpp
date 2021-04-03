#include <bits/stdc++.h>
using namespace std;

int main(){
  double v, t, s, d; cin >> v >> t >> s >> d;
  if(t <= d / (double)v && d / (double)v <= s){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}