#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n; cin >> n; vector<int> d(n);
  for(int i = 0; i < n; i++){cin >> d[i];}
  if(d[0] == 2){printf("1"); return 0;}
  int tp = 1; bool clr = false;
  int ans = 0;
  while(ans <= n){
    tp = d[tp - 1]; ans++;
    if(tp <= 2){clr = (tp == 2); break;}
  }
  cout << (clr ? ans : -1) << endl;
}