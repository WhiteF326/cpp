#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b; cin >> a >> b; int ans = 0;
  for(int i = a; i <= b; i++){
    string v = to_string(i); string rv = v;
    reverse(v.begin(), v.end());
    if(v == rv){ans++;}
  }
  cout << ans << endl;
}