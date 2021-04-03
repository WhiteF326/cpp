#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c; scanf("%d%d%d", &a, &b, &c);
  int ans = 0;
  while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
    int na = (b + c) / 2;
    int nb = (a + c) / 2;
    int nc = (a + b) / 2;
    if(na == a && nb == b && nc == c){ans = -2; na = 1;}
    ans++; a = na; b = nb; c = nc;
  }
  printf("%d", ans);
}
    