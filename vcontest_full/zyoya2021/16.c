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

int n, k;
int t[8][8];
int ans = 0;
int used[8];
int perm[8];

void dfs(int p, int d){
  perm[d] = p;
  used[p] = 1;
  if(d == n - 1){
    // 順列をテスト
    int res = 0;
    // for(int i = 0; i < n; i++){
    //   printf("%d ", perm[i]);
    // }printf("\n");
    for(int i = 0; i < n - 1; i++){
      res += t[perm[i]][perm[i + 1]];
    }
    res += t[perm[n - 1]][0];

    if(res == k){
      ans++;
    }
  }else{
    for(int i = 0; i < n; i++){
      if(used[i]) continue;
      dfs(i, d + 1);
    }
  }
  used[p] = 0;
  perm[d] = -1;
}

int main(){
  scanf("%d%d", &n, &k);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &t[i][j]);
    }
  }

  for(int i = 0; i < n; i++){
    used[i] = 0;
  }

  dfs(0, 0);

  printf("%d\n", ans);
}