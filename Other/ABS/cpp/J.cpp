#include <bits/stdc++.h>
using namespace std;

int rm(int a, int b, int c){
  return a * 10000 + b * 5000 + c * 1000;
}

int main(){
  int fc, goal; cin >> fc >> goal;
  for(int i = 0; i <= fc; i++){
    for(int j = 0; j <= fc; j++){
      if(i + j > fc){break;}
      for(int k = 0; k <= fc; k++){
        if(i + j + k > fc){break;}else if(i + j + k != fc){continue;}
        if(rm(i, j, k) == goal){
          cout << i << " " << j << " " << k << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}