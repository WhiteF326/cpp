#include <bits/stdc++.h>
using namespace std;

int main(){
  int pc; cin >> pc;
  int px = 0, py = 0, pt = 0;
  for(int i = 0; i < pc; i++){
    int t, x, y; cin >> t >> x >> y;
    if(abs(px - x) + abs(py - y) > (t - pt)){
      cout << "No" << endl; return 0;
    }else{
      if((x + y + t) % 2){
        cout << "No" << endl; return 0;
      }
    }
    px = x; py = y; pt = t;
  }
  cout << "Yes" << endl; return 0;
}