#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define vvvi vector<vector<vector<int>>>
#define vvi vector<vector<int>>
#define vi vector<int>


int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  
  while(a.size()){
    vvvi dp(a.size() + 1, vvi(2048, vi(3, 0)));
    vector<int> route(0);

    dp[1][a[0]][0] = 1, dp[1][a[0]][1] = 0, dp[1][a[0]][2] = 1;
    dp[1][0][0] = 1, dp[1][0][1] = 0, dp[1][0][2] = 0;
    
    for(int i = 2; i <= a.size(); i++){
      for(int j = 0; j < 2048; j++){
        if(dp[i - 1][j][0]){
          // use a[i - 1]
          dp[i][j ^ a[i - 1]][0] += dp[i - 1][j][0];
          dp[i][j ^ a[i - 1]][1] = j;
          dp[i][j ^ a[i - 1]][2] = 1;
          // don't use a[i - 1]
          dp[i][j][0] += dp[i - 1][j][0];
          dp[i][j][1] = j;
          dp[i][j][2] = 0;
        }
      }
      if(dp[i][0][2]){
        // restore
        ans++;
        int ptr = i, xr = 0;
        while(i > 0){
          if(dp[i][xr][2]){
            route.push_back(a[i - 1]);
          }
          xr = dp[i][xr][1];
          i--;
        }
        break;
      }
    }
    for(int v : route){
      a.erase(find(all(a), v));
    }
  }
  cout << ans << endl;
}