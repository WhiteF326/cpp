#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, x; scanf("%d%d%d", &n, &m, &x);
  vector<int> a(1, 0);
  for(int i = 0; i < m; i++){
    int ax; scanf("%d", &ax);
    if(ax < x){a[0]++;}else{a[1]++;}
  }
  printf("%d", (int)min(a[0], a[1]));
}