#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  int x, ans = 0; scanf("%d", &x);
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      for(int k = 0; k <= c; k++){
        if(x == i * 500 + j * 100 + k * 50){ans++;}
      }
    }
  }
  cout << ans << endl;
}