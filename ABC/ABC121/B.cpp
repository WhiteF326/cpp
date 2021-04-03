#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, c; scanf("%d%d%d", &n, &m, &c);
  vector<int> b(m);
  for(int i = 0; i < m; i++){scanf("%d", &b[i]);}
  int ans = 0;
  for(int i = 0; i < n; i++){
    int tmp = 0;
    for(int j = 0; j < m; j++){
      int x; scanf("%d", &x);
      tmp += x * b[j];
    }
    if(tmp + c > 0){ans++;}
  }
  printf("%d", ans);
}