#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;
#define chmin(a, b) a = min(a, b)

constexpr ll modv = 1000000007;
constexpr int a = 0, b = 1, c = 2;

int main(){
  int n; cin >> n;
  int ma, mb; cin >> ma >> mb;
  vector<vector<vector<int>>> ls(2, vector<vector<int>>(401, vector<int>(401, INT_MAX)));

  vector<vector<int>> t(n, vector<int>(3));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 3; j++) cin >> t[i][j];
  }
  if(n % 2){
    t.push_back({0, 0, 0});
    n++;
  }

  for(int i = 0; i < (1 << (n / 2)); i++){
    vector<vector<int>> sums(2, vector<int>(3, 0));
    for(int k = 0; k < n / 2; k++){
      if(i & (1 << k)){
        for(int j = 0; j < 2; j++){
          for(int l = 0; l < 3; l++) sums[j][l] += t[k + (j * n / 2)][l];
        }
      }
    }
    for(int j = 0; j < 2; j++) chmin(ls[j][sums[j][a]][sums[j][b]], sums[j][c]);
  }

  int ans = INT_MAX;
  for(int a = 0; a <= 400; a++){
    for(int b = 0; b <= 400; b++){
      if(ls[0][a][b] == INT_MAX) continue;
      for(int mul = 1; mul <= 40; mul++){
        int ta = ma * mul, tb = mb * mul;
        int na = ta - a, nb = tb - b;
        if(na < 0 || nb < 0) continue;
        if(ls[1][na][nb] != INT_MAX){
          chmin(ans, ls[0][a][b] + ls[1][na][nb]);
        }
      }
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << endl;
}
