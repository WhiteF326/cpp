#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int ans = INT_MAX;
  for(int i = 0; i < n; i++){
    int a, p ,x; cin >> a >> p >> x;
    if(a < x){ans = min(ans, p);}
  }
  cout << (ans == INT_MAX ? -1 : ans) << endl;
}