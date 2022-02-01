#include <stdio.h>

int min(int a, int b){
  if(a > b) return b;
  else return a;
}
int max(int a, int b){
  if(a > b) return a;
  else return b;
}

int main(){
  int a, b;
  scanf("%d%d", &a, &b);

  int add = a + b;
  int sub = a - b;
  int mul = a * b;

  printf("%d", max(add, max(sub, mul)));
}