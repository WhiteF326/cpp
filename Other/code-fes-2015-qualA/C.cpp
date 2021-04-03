#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, t; cin >> n >> t;
  vector<int> dif(n);
  int asum = 0, bsum = 0;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    dif[i] = a - b;
    asum += a;
    bsum += b;
  }
  if(asum <= t){
    cout << 0 << endl;
    return 0;
  }else if(bsum > t){
    cout << -1 << endl;
    return 0;
  }
  sort(dif.begin(), dif.end());
  int ans = 0;
  while(asum > t){
    asum -= dif[dif.size() - 1];
    ans++;
    dif.pop_back();
  }
  cout << ans << endl;
}
  