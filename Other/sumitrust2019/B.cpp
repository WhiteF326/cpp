#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n);
  int tryv = (int)round(n * 100 / (double)108);
  for(int i = tryv - 1; i <= tryv + 1; i++){
    if(i * 108 / 100 == n){printf("%d", i); return 0;}
  }
  printf(":("); return 0;
}