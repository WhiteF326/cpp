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
  int n; scanf("%d", &n);
  int d[100][2];
  for(int i = 0; i < n; i++){
    scanf("%d%d", &d[i][0], &d[i][1]);
  }

  for(int i = 0; i < n - 2; i++){
    if(d[i][0] == d[i][1] && d[i + 1][0] == d[i + 1][1] && d[i + 2][0] == d[i + 2][1]){
      printf("Yes");
      return 0;
    }
  }
  printf("No");
}