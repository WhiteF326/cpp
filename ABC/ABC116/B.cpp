#include <bits/stdc++.h>
using namespace std;

int main(){
  int s; scanf("%d", &s); int a = s;
  int ans = 1; bool endflg = false;
  vector<bool> hist(1000000, false); hist[s] = true;
  while(!endflg){
    ans++;
    if(a % 2){a = 3 * a + 1;}else{a = a / 2;}
    if(hist[a]){endflg = true;}else{hist[a] = true;}
  }
  printf("%d", ans);
}