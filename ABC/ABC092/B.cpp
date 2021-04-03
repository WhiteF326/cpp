#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, d, x; scanf("%d%d%d", &n, &d, &x);
  for(int i = 0; i < n; i++){
    int a; scanf("%d", &a);
    x += (int)ceil(d / (double)a);
  }
  printf("%d", x);
}