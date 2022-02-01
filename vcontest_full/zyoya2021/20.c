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
  char s[101][101];
  for(int i = 0; i < n; i++) scanf("%s", s[i]);

  int m;
  scanf("%d", &m);
  char t[101][101];
  for(int i = 0; i < m; i++) scanf("%s", t[i]);

  int ans = 0;
  for(int i = 0; i < n; i++){
    int res = 0;
    for(int j = 0; j < n; j++){
      if(strcmp(s[i], s[j]) == 0) res++;
    }
    for(int j = 0; j < m; j++){
      if(strcmp(s[i], t[j]) == 0) res--;
    }

    ans = max(ans, res);
  }

  printf("%d", ans);
}