#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<int> d(n);
  for(int i = 0; i < n; i++) cin >> d[i];
  int ans = 0;
  for(int i = 0; i < pow(3, n); i++){
    int res = 1;
    for(int j = 0; j < n; j++){
      int t = (d[j] + ((i / (int)pow(3, n - j - 1)) % 3) - 1);
      res *= (t == 0 ? 0 : (t % 2) + 2);
    }
    //if(res > 0 && res % 2 == 0) ans++;
    if(res % 2 == 0) ans++;
  }
  cout << ans << endl;
}