#include <bits/stdc++.h>
using namespace std;

int main(){
  int x; scanf("%d", &x); bool cflg = true; x--;
  if(x < 2){printf("%d", x + 1); return 0;}
  while(cflg){
    x++; cflg = false;
    for(int i = 2; i <= (int)sqrt(x); i++){
      if(x % i == 0){cflg = true;}
    }
  }
  printf("%d", x); return 0;
}