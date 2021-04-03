#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; scanf("%d%d", &n, &k);
  int ans = 0;
  for(int i = 0; i < n; i++){
    int x; scanf("%d", &x);
    if(k - x > x){ans += x * 2;}else{ans += (k - x) * 2;}
  }
  printf("%d", ans);
}