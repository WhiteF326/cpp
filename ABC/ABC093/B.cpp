#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a, b, x; cin >> a >> b >> x;
  vector<int> ans(0);
  for(int i = 0; i < x; i++){
    if(a + i <= b){ans.push_back(a + i);}
    if(b - i >= a){ans.push_back(b - i);}
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for(int i = 0; i < ans.size(); i++){cout << ans[i] << endl;}
}