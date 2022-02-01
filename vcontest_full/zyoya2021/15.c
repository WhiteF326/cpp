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

  int t[100];
  int ans = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", &t[i]);
    ans += t[i];
  }

  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    int p, x;
    scanf("%d%d", &p, &x);

    printf("%d\n", ans - t[p - 1] + x);
  }
}