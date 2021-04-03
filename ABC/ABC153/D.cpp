#include <bits/stdc++.h>
using namespace std;

int main(){
  long h; scanf("%ld", &h);
  long ans = 0, ac = 0;
  while((h / pow(2, ac)) >= 1){ans += pow(2, ac);ac++;}
  printf("%ld", ans);
}