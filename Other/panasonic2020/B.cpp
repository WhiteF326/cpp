#include <bits/stdc++.h>
using namespace std;

int main(){
  long long h, w; scanf("%ld%ld", &h, &w);
  if(h == 1 || w == 1){printf("1");}else{printf("%ld", (long long)ceil(h * w / 2.0));}
}