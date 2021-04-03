#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> xv(n);
  int mp = 101, xp = 0;
  for(int i = 0; i < n; i++){
    int tmp; cin >> tmp;
    xv[i] = tmp; mp = min(mp, tmp); xp = max(xp, tmp);
  }
  int ans = INT_MAX;
  for(int i = 0; i <= 100; i++){
    int tmp = 0;
    for(int j = 0; j < n; j++){
      tmp += (int)pow(xv[j] - i, 2);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}