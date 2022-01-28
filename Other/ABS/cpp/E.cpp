#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  for(int i = 0; i < (a + 1) * (b + 1) * (c + 1); i++){
    int tmp = 500 * (i / ((b + 1) * (c + 1)));
    tmp += 100 * ((i / (c + 1)) % (b + 1));
    tmp += 50 * (i % (c + 1));
    if(tmp == x){
      ans++;
    }
  }
  cout << ans << endl;
}