#include <bits/stdc++.h>
using namespace std;

int main(){
  int cc; cin >> cc;
  vector<int> cn(cc);
  for(int i = 0; i < cc; i++){
    cin >> cn[i];
  }
  int a = 0, b = 0; bool f = true;
  for(int i = 0; i < cc; i++){
    int max = 0;
    for(int j = 0; j < cn.size(); j++){
      if(cn[max] < cn[j]){
        max = j;
      }
    }
    if(f){ a += cn[max]; }else{ b += cn[max]; }
    cn.erase(cn.begin() + max);
    f = !f;
  }
  cout << a - b << endl;
  return 0;
}