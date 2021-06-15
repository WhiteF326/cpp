#include <stdio.h>

int main(){
  int x, a, b; scanf("%d\n%d\n%d", &x, &a, &b);
  printf("%d", (x - a) % b); fflush(stdout);
}