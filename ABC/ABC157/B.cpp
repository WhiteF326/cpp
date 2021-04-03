#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> pt(100, vector<int>(2, -1));
  vector<vector<bool>> tbl(3, vector<bool>(3, false));
  for(int i = 0; i < 9; i++){
    int tmp; scanf("%d", &tmp);
    pt[tmp - 1][0] = i / 3; pt[tmp - 1][1] = i % 3;
  }
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int tmp; scanf("%d", &tmp);
    if(pt[tmp - 1][0] != -1){tbl[pt[tmp - 1][0]][pt[tmp - 1][1]] = true;}
  }
  bool ans = false;
  for(int i = 0; i < 3; i++){
    bool tmp = true;
    for(int j = 0; j < 3; j++){
      if(!tbl[i][j]){tmp = false;}
    }
    if(tmp){ans = true;}
    tmp = true;
    for(int j = 0; j < 3; j++){
      if(!tbl[j][i]){tmp = false;}
    }
    if(tmp){ans = true;}
  }
  if(tbl[0][0] && tbl[1][1] && tbl[2][2]){ans = true;}
  if(tbl[2][0] && tbl[1][1] && tbl[0][2]){ans = true;}
  if(ans){printf("Yes");}else{printf("No");}
  return 0;
}