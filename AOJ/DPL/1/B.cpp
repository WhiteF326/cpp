#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // dp[i][w]
  int n, w; cin >> n >> w;
  vector<pair<int, int>> items(n);
  for(int i = 0; i < n; i++){
    int v, w; cin >> v >> w;
    items[i] = make_pair(v, w);
  }
}