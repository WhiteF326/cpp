#include <bits/stdc++.h>
using namespace std;

int main(){
  int size; cin >> size;
  vector<int> v(size, 0);
  for(int i = 0; i < size; i++){
    cin >> v[i];
  }
  int ans = 0;
  bool cflg = true;
  while(cflg){
    for(int i = 0; i < size; i++){
      if(v[i] % 2){ cflg = false; break; }else{ v[i] = v[i] / 2; }
    }
    if(cflg){ans++;}
  }
  cout << ans << endl;
}