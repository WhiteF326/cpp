#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b; scanf("%d%d", &a, &b);
  int ans = 0;
  for(int i = 1; i <= a; i++){
    for(int j = 0; j < 31; j++){
      if(i == a && j > b)break;
      if(i == j) ans++;
    }
  }
  cout << ans << endl;
}