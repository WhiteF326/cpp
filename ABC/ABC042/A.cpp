#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> in(3); for(int i = 0; i < 3; i++) cin >> in[i];
  sort(in.begin(), in.end());
  if(in[0] == 5 && in[1] == 5 && in[2] == 7) cout << "YES";
  else cout << "NO";
  cout << endl;
}