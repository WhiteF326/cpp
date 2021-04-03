#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<long long> vals(4);
  for(int i = 0; i < 4; i++) cin >> vals[i];
  long long t = vals[3]; int n; cin >> n; long long ans = 0;
  //偶数分
  vals[0] *= 8; vals[1] *= 4; vals[2] *= 2;
  sort(vals.begin(), vals.end());
  ans += vals[0] * (n / 2);
  //端数？
  if(n % 2){
    if(vals[0] == t){
      ans += vals[1] / 2;
    }else{
      ans += vals[0] / 2;
    }
  }
  cout << ans << endl;
}