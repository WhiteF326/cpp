#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; scanf("%d%d", &n, &m);
  int val = stoi(to_string(n) + to_string(m));
  for(int i = 0; i < 1000; i++){
    if(i * i == val){printf("Yes"); return 0;}
  }
  printf("No"); return 0;
}