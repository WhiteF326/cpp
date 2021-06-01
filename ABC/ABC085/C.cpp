#include <bits/stdc++.h>
using namespace std;

int rm(int a, int b, int c){
  return a * 10000 + b * 5000 + c * 1000;
}
 
int main(){
  int fc, goal; cin >> fc >> goal;
  for(int i = 0; i <= fc; i++){
    for(int j = 0; j <= fc - i; j++){
      if(i + j > fc) break;
      int k = fc - (i + j);
      if(rm(i, j, k) == goal){
        cout << i << " " << j  << " " << k << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}