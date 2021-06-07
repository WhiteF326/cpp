#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;

  vector<vector<int>> cnt(10, vector<int>(10, 0));
  
  for(int i = 1; i <= n; i++){
    int b = i % 10;
    int t = -1, x = i;
    while(0 < x){
      t = x % 10;
      x /= 10;
    }
    cnt[t][b]++;
  }
  ll ans = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      ans += cnt[i][j] * cnt[j][i];
    }
  }
  cout << ans << endl;
}