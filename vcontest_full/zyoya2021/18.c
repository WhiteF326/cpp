#include <stdio.h>
#include <string.h>

int min(int a, int b){
  if(a > b) return b;
  else return a;
}
int max(int a, int b){
  if(a > b) return a;
  else return b;
}

int main(){
  char s[3];
  scanf("%s", s);

  if(s[1] == 'B'){
    printf("ARC");
  }else{
    printf("ABC");
  }
}