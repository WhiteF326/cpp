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
  char s[100];
  scanf("%s", s);

  int flg = 0;
  for(int i = 0; i < strlen(s); i++){
    if(s[i] == 'C'){
      flg = 1;
    }
    if(flg && s[i] == 'F'){
      printf("Yes");
      return 0;
    }
  }
  printf("No");
}