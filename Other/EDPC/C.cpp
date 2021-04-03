#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; vector<vector<long long>> dp(n, vector<long long>(3, 0));
  vector<vector<int>> h(n, vector<int>(3));
  for(int i = 0; i < n; i++){for(int j = 0; j < 3; j++){cin >> h[i][j];}}
  for(int i = 0; i < 3; i++){dp[0][i] = h[0][i];}
  for(int i = 1; i < n; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(j != k || i == 0){
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + h[i][j]);
        }
      }
    }
  }
  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
}