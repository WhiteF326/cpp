#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int ans = 1000;
  for(int i = 0; i < s.length()-2; i++){
    int xv = stoi(s.substr(i, 3));
    ans = min(ans, (int)abs(753 - xv));
  }
  printf("%d", ans);
}