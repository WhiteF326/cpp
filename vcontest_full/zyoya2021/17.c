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
  int n;
  scanf("%d", &n);

  int t[200000];
  for(int i = 0; i < n; i++){
    t[i] = 0;
  }
  for(int i = 0; i < n - 1; i++){
    int v; scanf("%d", &v);
    t[v - 1]++;
  }

  for(int i = 0; i < n; i++){
    printf("%d\n", t[i]);
  }
}