#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  vector<vector<ll>> prog(n, vector<ll>(21, 0));
  prog[0][a[0]]++;
  for(int i = 1; i < n - 1; i++){
    for(int j = 0; j < 21; j++){
      // +
      if(prog[i - 1][j] && j + a[i] <= 20){
        prog[i][j + a[i]] += prog[i - 1][j];
      }
      // -
      if(prog[i - 1][j] && j - a[i] >= 0){
        prog[i][j - a[i]] += prog[i - 1][j];
      }
    }
  }
  cout << prog[n - 2][a[n - 1]] << endl;
}