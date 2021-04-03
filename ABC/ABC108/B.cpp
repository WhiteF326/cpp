#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
  int vx = c - a, vy = d - b;
  printf("%d %d %d %d", c - vy, d + vx, c - vy - vx, d + vx - vy);
}