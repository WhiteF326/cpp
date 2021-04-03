#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b; scanf("%d%d%d", &n, &a, &b);
  int ct = a + b, ox = b;
  string usr; cin >> usr;
  for(int i = 0; i < n; i++){
    string tmp = usr.substr(i, 1);
    if(tmp == "a" && ct > 0){
      ct--; printf("Yes\n");
    }else if(tmp == "b" && ct > 0 && ox > 0){
      ct--; ox--; printf("Yes\n");
    }else{printf("No\n");}
  }
}