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
  char s[100000] = "";
  scanf("%s", s);
  int n = strlen(s);

  int a = 0, b = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == '0'){
      a++;
    }else{
      b++;
    }
  }

  printf("%d\n", min(a, b) * 2);
}