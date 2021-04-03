#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, a, b; scanf("%ld%ld%ld", &n, &a, &b);
  long v = (n / (a + b)), ans = v * a;
  if(n - a >= v * (a + b)){ans += a;}else{ans += n - (a + b) * v;}
  printf("%ld", ans);
}