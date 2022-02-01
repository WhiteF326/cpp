#include <stdio.h>
#include <string.h>

int min(int a, int b){
  if(a > b) return b;
  else return a;
}
int max(int a, int b){
  if(a > b) return a;
  else return b;
}

int main(){
  long long k;
  scanf("%lld", &k);

  char a[17], b[17];
  scanf("%s%s", &a, &b);

  long long la = 0, lb = 0;
  long long cur = 1LL, i = strlen(a) - 1;
  while(i >= 0){
    la += (long long)((a[i] - '0') % k) * cur;
    cur *= k;
    i--;
  }
  cur = 1, i = strlen(b) - 1;
  while(i >= 0){
    lb += (long long)((b[i] - '0') % k) * cur;
    cur *= k;
    i--;
  }
  
  printf("%lld\n", la * lb);
}