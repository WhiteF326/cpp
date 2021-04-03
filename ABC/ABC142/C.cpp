#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n);
  vector<int> t(n);
  for(int i = 0; i < n; i++){
    int a; scanf("%d", &a); t[a - 1] = i + 1;
  }
  for(int i = 0; i < n; i++){
    printf("%d", t[i]);
    if(i != n - 1){printf(" ");}
  }
}