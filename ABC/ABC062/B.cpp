#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  string outstr; for(int i = 0; i < w + 2; i++){outstr += "#";}
  cout << outstr << endl;
  for(int i = 0; i < h; i++){
    string t; cin >> t;
    cout << "#" << t << "#" << endl;
  }
  cout << outstr << endl;
}