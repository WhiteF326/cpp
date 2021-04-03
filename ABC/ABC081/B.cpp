#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n); vector<int> a(n);
  for(int i = 0; i < n; i++){scanf("%d", &a[i]);}
  int ans = 0;
  while(true){
    int s = 0;
    for(int i = 0; i < n; i++){if(!(a[i] % 2)){a[i] /= 2; s++;}}
    if(s != n){break;}else{ans++;}
  }
  printf("%d", ans);
}