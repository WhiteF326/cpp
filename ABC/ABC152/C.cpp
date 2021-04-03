#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n); int ans = 1;
  int tmin; scanf("%d", &tmin);
  for(int i = 0; i < n - 1; i++){
    int t; scanf("%d", &t);
    if(tmin > t){ans++;}
    tmin = min(tmin, t);
  }
  cout << ans << endl;
}