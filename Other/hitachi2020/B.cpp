#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, m; scanf("%d%d%d", &a, &b, &m);
  int ma = 200001, mb = 200001, ud;
  vector<int> ara(a), arb(b);
  for(int i = 0; i < a; i++){
    int ta; scanf("%d", &ta); ma = min(ma, ta);
    ara[i] = ta;
  }
  for(int i = 0; i < b; i++){
    int tb; scanf("%d", &tb); mb = min(mb, tb);
    arb[i] = tb;
  }
  ud = ma + mb; int wd = 200001;
  for(int i = 0; i < m; i++){
    int x, y, c; scanf("%d%d%d", &x, &y, &c);
    int tc = ara[x - 1] + arb[y - 1] - c;
    wd = min(wd, tc);
  }
  printf("%d", (int)min(ud, wd)); return 0;
}